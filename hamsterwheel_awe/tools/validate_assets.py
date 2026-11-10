#!/usr/bin/env python3
"""Check provenance, strict parsing, topology counts and Android scene output."""
from pathlib import Path
import hashlib
import json
import math
import struct
from formats import world, mesh, cached

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT/'original/hamsterball'


def main():
    manifest = json.loads((ROOT/'original/manifest.json').read_text())
    files = {str(p.relative_to(SOURCE)).lower(): p for p in SOURCE.rglob('*') if p.is_file()}
    for record in manifest['files']:
        data = (SOURCE/record['path']).read_bytes()
        assert len(data) == record['size']
        assert hashlib.sha256(data).hexdigest() == record['sha256'], record['path']
    counts = dict(worlds=0, models=0, caches=0, topology_matches=0)
    for name, path in files.items():
        if name.endswith('.meshworld'):
            scene = world(path)
            counts['worlds'] += 1
            for group in scene['batches']:
                assert len(group['indices']) % 3 == 0
                for texture in group['material']['textures']:
                    assert 'textures/'+texture.lower() in files, texture
            cache = files.get(str(path.relative_to(SOURCE).with_suffix('.cached')).lower())
            if cache:
                data = cached(cache)
                assert sum(len(g['indices']) for g in scene['batches']) == len(data['indices']), name
                counts['topology_matches'] += 1
        elif name.endswith('.mesh'):
            mesh(path)
            counts['models'] += 1
        elif name.endswith('.cached'):
            cached(path)
            counts['caches'] += 1
    converted = 0
    for p in (ROOT/'android/app/src/main/assets').rglob('*.hwa'):
        data = p.read_bytes()
        assert data[:4] == b'HWA1'
        length, = struct.unpack_from('<I', data, 4)
        header = json.loads(data[8:8+length])
        count = sum(g['count'] for g in header['groups'])
        assert len(data) == 8+length+count*32, p
        assert all(math.isfinite(x[0]) for x in struct.iter_unpack('<f', data[8+length:])), p
        converted += 1
    races = json.loads((ROOT/'android/app/src/main/assets/races.json').read_text())
    assert len(races) == 15
    for race in races:
        assert (ROOT/'android/app/src/main/assets/scenes'/f'{race["id"]}.hwa').is_file()
    result = dict(preserved_files=len(manifest['files']), converted_scenes=converted,
                  races=len(races), **counts)
    (ROOT/'docs/validation-result.json').write_text(json.dumps(result, indent=2))
    print(json.dumps(result))


if __name__ == '__main__':
    main()
