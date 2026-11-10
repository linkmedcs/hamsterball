"""Readers for the little-endian Raptisoft mesh formats. No EXE execution."""
import struct


class Reader:
    def __init__(self, path):
        self.data = path.read_bytes()
        self.pos = 0

    def unpack(self, fmt):
        fmt = '<' + fmt
        value = struct.unpack_from(fmt, self.data, self.pos)
        self.pos += struct.calcsize(fmt)
        return value

    def uint(self):
        value, = self.unpack('I')
        if value > 2_000_000:
            raise ValueError(f'Unexpected count {value} at {self.pos - 4}')
        return value

    def string(self):
        n = self.uint()
        if n > 1024 or n == 0:
            raise ValueError(f'Invalid string size {n} at {self.pos - 4}')
        raw = self.data[self.pos:self.pos + n]
        self.pos += n
        if len(raw) != n or raw[-1] != 0:
            raise ValueError('Unterminated string')
        return raw[:-1].decode('cp1252')

    def material(self):
        colors = self.unpack('17f')
        flags = self.uint()
        textures = [self.string() for _ in range(self.uint())]
        return {'diffuse': colors[:4], 'flags': flags, 'textures': textures}

    def done(self):
        if self.pos != len(self.data):
            raise ValueError(f'Unparsed bytes: {len(self.data) - self.pos}, offset {self.pos}')


def cached(path):
    r = Reader(path)
    magic, version = r.unpack('If')
    if magic != 0xBEEF:
        raise ValueError(f'Not a cached mesh: {path}')
    vertices = [r.unpack('8f') for _ in range(r.uint())]
    count = r.uint()
    indices = r.unpack(f'{count}H')
    groups = r.unpack(f'{count // 3}I')
    assert count % 3 == 0 and max(indices, default=0) < len(vertices)
    r.done()
    return {'version': version, 'vertices': vertices, 'indices': indices, 'groups': groups}


def world(path):
    r = Reader(path)
    markers = []
    for _ in range(r.uint()):
        name = r.string()
        position = r.unpack('3f')
        rotation = r.unpack('3f')
        materials = [r.material() for _ in range(r.uint())]
        markers.append(dict(name=name, position=position, rotation=rotation, materials=materials))
    curves = []
    for _ in range(r.uint()):
        name = r.string()
        points = [r.unpack('3f') for _ in range(r.uint())]
        curves.append(dict(name=name, points=points))
    lights = []
    for _ in range(r.uint()):
        lights.append(dict(type=r.uint(), values=r.unpack('9f')))
    environment = r.unpack('6f')
    vertices = [r.unpack('8f') for _ in range(r.uint())]
    batches = []

    def node(depth=0):
        if depth > 50:
            raise ValueError('Octree too deep')
        bounds = r.unpack('6f')
        children = r.uint()
        for _ in range(children):
            node(depth + 1)
        if children:
            return bounds
        for _ in range(r.uint()):
            name = r.string()
            material = r.material()
            triangles = []
            for _ in range(r.uint()):
                count, start = r.unpack('II')
                if start + count + 2 > len(vertices):
                    raise ValueError('Strip exceeds vertex buffer')
                for i in range(count):
                    ids = (start+i, start+i+1, start+i+2)
                    if i % 2:
                        ids = (ids[1], ids[0], ids[2])
                    triangles.extend(ids)
            batches.append(dict(name=name, material=material, indices=triangles))
        return bounds

    bounds = node()
    r.done()
    return dict(markers=markers, curves=curves, lights=lights, environment=environment,
                vertices=vertices, batches=batches, bounds=bounds)


def mesh(path):
    r = Reader(path)
    parts = []
    for _ in range(r.uint()):
        name = r.string()
        position = r.unpack('3f')
        material = r.material()
        vertices = []
        indices = []
        for _ in range(r.uint()):
            count = r.uint()
            start = len(vertices)
            vertices.extend(r.unpack('8f') for _ in range(count + 2))
            for i in range(count):
                tri = (start+i, start+i+1, start+i+2)
                indices.extend((tri[1], tri[0], tri[2]) if i % 2 else tri)
        parts.append(dict(name=name, position=position, material=material,
                          vertices=vertices, indices=indices))
    bounds = r.unpack('6f')
    for part in parts:
        part['bounds'] = bounds
    r.done()
    return parts
