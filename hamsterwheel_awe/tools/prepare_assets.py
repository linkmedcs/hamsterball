#!/usr/bin/env python3
"""Convert preserved original resources to the Android port's scene format."""
from pathlib import Path
import collections
import hashlib
import json
import shutil
import struct
import xml.etree.ElementTree as ET
from formats import world, mesh, cached

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / 'original/hamsterball'
OUTPUT = ROOT / 'android/app/src/main/assets'
RACES = [
    ('level1', 'Beginner', 'BEGINNERRACE'),
    ('levelcascade', 'Cascade', 'CASCADERACE'),
    ('level2', 'Intermediate', 'INTERMEDIATERACE'),
    ('level3', 'Dizzy', 'DIZZYRACE'),
    ('level4', 'Tower', 'TOWERRACE'),
    ('levelup', 'Up', 'UPRACE'),
    ('leveldark', 'Neon', 'NEONRACE'),
    ('level5', 'Expert', 'EXPERTRACE'),
    ('level6', 'Odd', 'ODDRACE'),
    ('level8', 'Toob', 'TOOBRACE'),
    ('levelglass', 'Glass', 'GLASSRACE'),
    ('level7', 'Wobbly', 'WOBBLYRACE'),
    ('level9', 'Sky', 'SKYRACE'),
    ('level10', 'Master', 'MASTERRACE'),
    ('levelimpossible', 'Impossible', 'IMPOSSIBLERACE'),
]


def android_vertex(v):
    # Original D3D coordinates -> right-handed OpenGL. Keep UV as stored.
    return (v[0], v[1], -v[2], v[3], v[4], -v[5], v[6], v[7])


def write_scene(path, scene):
    grouped = collections.OrderedDict()
    for b in scene['batches']:
        material = b['material']
        key = (b['name'], tuple(material['diffuse']), tuple(material['textures']))
        grouped.setdefault(key, []).extend(b['indices'])
    groups = []
    geometry = bytearray()
    for (name, color, textures), indices in grouped.items():
        if not indices:
            continue
        groups.append(dict(name=name, color=color,
                           texture=textures[0].lower() if textures else '',
                           count=len(indices)))
        for i in indices:
            geometry.extend(struct.pack('<8f', *android_vertex(scene['vertices'][i])))
    meta = {k: v for k, v in scene.items() if k not in ('vertices', 'batches')}
    meta['groups'] = groups
    for m in meta.get('markers', []):
        m['position'] = (m['position'][0], m['position'][1], -m['position'][2])
    header = json.dumps(meta, separators=(',', ':')).encode()
    path.write_bytes(b'HWA1' + struct.pack('<I', len(header)) + header + geometry)


def main():
    for folder in ('scenes', 'models', 'textures', 'sounds'):
        (OUTPUT / folder).mkdir(parents=True, exist_ok=True)
    inventory = []
    for path in sorted(ORIGINAL.rglob('*')):
        if not path.is_file():
            continue
        ext = path.suffix.lower()
        if ext == '.meshworld':
            scene = world(path)
            write_scene(OUTPUT / 'scenes' / (path.stem.lower() + '.hwa'), scene)
            inventory.append(dict(path=str(path.relative_to(ORIGINAL)), kind='world',
                                  vertices=len(scene['vertices']), markers=len(scene['markers'])))
        elif ext == '.mesh':
            parts = mesh(path)
            scene = dict(vertices=[], batches=[], markers=[], environment=[.1]*6)
            for part in parts:
                offset = len(scene['vertices'])
                scene['vertices'].extend(part['vertices'])
                scene['batches'].append(dict(name=part['name'], material=part['material'],
                                             indices=[offset+i for i in part['indices']]))
            write_scene(OUTPUT / 'models' / (path.stem.lower() + '.hwa'), scene)
            inventory.append(dict(path=str(path.relative_to(ORIGINAL)), kind='mesh', parts=len(parts)))
        elif ext == '.cached':
            cache = cached(path)
            inventory.append(dict(path=str(path.relative_to(ORIGINAL)), kind='cache',
                                  vertices=len(cache['vertices']), triangles=len(cache['indices'])//3))
        elif path.parent.name.lower() in ('textures', 'sounds') and ext in ('.png', '.jpg', '.bmp', '.ogg'):
            folder = path.parent.name.lower()
            target = OUTPUT / folder / path.name.lower()
            if target.exists() and target.read_bytes() != path.read_bytes():
                raise ValueError(f'Case collision: {path}')
            shutil.copyfile(path, target)
    racefile = next(p for p in ORIGINAL.iterdir() if p.name.lower() == 'racedata.xml')
    config = ET.fromstring('<RACES>' + racefile.read_text() + '</RACES>')
    races = []
    for id_, title, tag in RACES:
        node = config.find(tag)
        if node is None:
            raise ValueError(f'Unknown race configuration {tag}')
        races.append(dict(id=id_, title=title,
                          parameters={n.tag: float(n.text) for n in node}))
    (OUTPUT / 'races.json').write_text(json.dumps(races, indent=2))
    (ROOT / 'docs/asset-validation.json').write_text(json.dumps(inventory, indent=2))
    print(f'Converted {sum(x["kind"]=="world" for x in inventory)} worlds, '
          f'{sum(x["kind"]=="mesh" for x in inventory)} models; '
          f'validated {sum(x["kind"]=="cache" for x in inventory)} caches; '
          f'{len(races)} races configured.')


if __name__ == '__main__':
    main()
