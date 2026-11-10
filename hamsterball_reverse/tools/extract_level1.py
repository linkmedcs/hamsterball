#!/usr/bin/env python3
"""Export static first-course evidence, keeping runtime semantics unverified."""
import collections
import hashlib
import json
import re
import sys
import xml.etree.ElementTree as ET
from pathlib import Path
from original_formats import world, cached

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'analysis/inherited'))
from analyze_exe import PE


def main():
    game = ROOT/'original/game'
    pe = PE(game/'hamsterball.exe')
    w = world(game/'Levels/Level1.MESHWORLD')
    cache_path = next(p for p in (game/'Levels').iterdir() if p.name.lower() == 'level1.cached')
    cache = cached(cache_path)
    race = ET.fromstring('<root>'+ (game/'Racedata.xml').read_text() + '</root>').find('BEGINNERRACE')
    instructions = (ROOT/'analysis/inherited/hamsterball-4.2.asm').read_text().splitlines()
    def snippet(start, end):
        lines = []
        for line in instructions:
            match = re.match(r'\s*([0-9a-f]+):', line)
            if match and start <= int(match[1],16) < end:
                lines.append(line)
        return lines
    report = dict(
        executable_sha256=hashlib.sha256(pe.data).hexdigest(), status='static_evidence_only',
        course=dict(resource='Levels/Level1.MESHWORLD', public_race_key='BEGINNERRACE',
                    internal_board_name=pe.string(0x50d62c), constructor='0x414240',
                    vtable='0x4f82d8', loader='0x414310',
                    strings={hex(a):pe.string(a) for a in [0x50d62c,0x50d63c,0x50d64c,0x50d65c,0x50d66c]},
                    race_values={x.tag:float(x.text) for x in race}),
        misleading_internal_name=dict(constructor='0x41dab0', vtable='0x4f89d8',
                     strings={hex(a):pe.string(a) for a in [0x50e2a8,0x50e2bc,0x50e2cc,0x50e2d8,0x50e2e8]},
                     conclusion='Board (Beginner) selects CASCADERACE/levelcascade; do not use as first-course mapping'),
        geometry=dict(vertex_count=len(w['vertices']), triangle_count=sum(len(b['indices'])//3 for b in w['batches']),
                      cache_vertex_count=len(cache['vertices']), cache_triangle_count=len(cache['indices'])//3,
                      bounds=w['bounds']),
        markers=w['markers'], marker_counts=dict(collections.Counter(m['name'] for m in w['markers'])),
        curves=w['curves'], lights=w['lights'], environment=w['environment'],
        batches=[dict(name=b['name'], triangle_count=len(b['indices'])//3, material=b['material']) for b in w['batches']],
        notes=['Resource markers/curves are parsed values, not verified gameplay state.',
               'N:GOAL, E:LIMIT and E:NODIZZY require code interpretation.',
               'No first-course dynamic object list is claimed complete before constructor/update review.',
               'Static start marker is not a measured ball center or spawn state.'])
    (ROOT/'analysis/level1-static.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n')
    with (ROOT/'analysis/course-mapping-evidence.asm').open('w') as f:
        for start,end in [(0x414240,0x4142da),(0x414310,0x4143ce),(0x41dab0,0x41db80),(0x41dc10,0x41dd30)]:
            f.write(f'\n; Evidence range {start:#x}..{end:#x}\n'+'\n'.join(snippet(start,end))+'\n')
    print(json.dumps(dict(course=report['course'], geometry=report['geometry'],
                          marker_counts=report['marker_counts'], curves=[c['name'] for c in w['curves']]),ensure_ascii=False,indent=2))


if __name__ == '__main__':
    main()
