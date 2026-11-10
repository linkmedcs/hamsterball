#!/usr/bin/env python3
"""Freeze and verify the extracted original; never run the installer/game."""
import argparse
import hashlib
import json
import shutil
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PREVIOUS = ROOT.parent / 'hamsterwheel_awe'
EXPECTED_EXE = '047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58'


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def inventory(folder):
    return [dict(path=p.relative_to(folder).as_posix(), size=p.stat().st_size,
                 sha256=digest(p)) for p in sorted(folder.rglob('*')) if p.is_file()]


def verify(folder, expected):
    actual = inventory(folder)
    if actual != sorted(expected, key=lambda x: x['path']):
        want = {x['path']: x for x in expected}
        got = {x['path']: x for x in actual}
        changes = [k for k in sorted(want.keys() | got.keys()) if want.get(k) != got.get(k)]
        raise RuntimeError(f'Baseline mismatch: {changes}')
    if digest(folder / 'hamsterball.exe') != EXPECTED_EXE:
        raise RuntimeError('Unexpected executable version')
    return actual


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--verify', action='store_true')
    args = parser.parse_args()
    original = ROOT / 'original'
    frozen = original / 'game'
    lock = original / 'baseline-lock.json'
    if not args.verify and not lock.exists():
        previous_manifest = PREVIOUS / 'original/manifest.json'
        manifest = json.loads(previous_manifest.read_text())
        source = PREVIOUS / 'original/hamsterball'
        verify(source, manifest['files'])
        installer = ROOT.parent / manifest['installer']
        if digest(installer) != manifest['installer_sha256']:
            raise RuntimeError('Original installer checksum mismatch')
        original.mkdir(exist_ok=True)
        if not frozen.exists():
            shutil.copytree(source, frozen)
        files = verify(frozen, manifest['files'])
        provenance = []
        for name in ['analyze_exe.py', 'probe_original.py', 'static-inventory.json',
                     'board-map.json', 'anchors.tsv', 'original-probe-results.json',
                     'hamsterball-4.2.asm', 'FEASIBILITY.md', 'collision-update.asm',
                     'pe-headers.txt']:
            src = PREVIOUS / 'research' / name
            if not src.exists():
                continue
            dst = ROOT / 'analysis/inherited' / name
            dst.parent.mkdir(exist_ok=True)
            shutil.copy2(src, dst)
            provenance.append(dict(source=str(src.relative_to(ROOT.parent)),
                                   destination=str(dst.relative_to(ROOT)), sha256=digest(dst)))
        shutil.copy2(previous_manifest, original / 'extraction-manifest.json')
        shutil.copy2(PREVIOUS / 'tools/formats.py', ROOT / 'tools/original_formats.py')
        provenance.append(dict(source='hamsterwheel_awe/tools/formats.py',
                               destination='tools/original_formats.py',
                               sha256=digest(ROOT / 'tools/original_formats.py')))
        config = [x for x in files if x['path'].lower().endswith(('.cfg', '.ini', '.sav', '.dat'))
                  or x['path'] in ['Racedata.xml', 'Jukebox.xml']]
        record = dict(schema_version=1, created_utc=datetime.now(timezone.utc).isoformat(),
                      source='hamsterwheel_awe/original/hamsterball',
                      installer=dict(path='../' + installer.name, sha256=digest(installer)),
                      executable_sha256=EXPECTED_EXE, file_count=len(files), files=files,
                      supplied_config_and_save_candidates=config,
                      inherited_evidence=provenance,
                      runtime_config_status='Unknown: no game runtime captured at freeze time',
                      save_state_status='No runtime-generated state captured; supplied CFG semantics unverified',
                      rules=['Do not launch game in original/game; use a separate working copy.',
                             'Do not regenerate the lock to accept changes. Investigate mismatches.'])
        lock.write_text(json.dumps(record, ensure_ascii=False, indent=2) + '\n')
    record = json.loads(lock.read_text())
    files = verify(frozen, record['files'])
    for item in record['inherited_evidence']:
        if digest(ROOT / item['destination']) != item['sha256']:
            raise RuntimeError('Inherited evidence changed: ' + item['destination'])
    if digest(ROOT / record['installer']['path']) != record['installer']['sha256']:
        raise RuntimeError('Installer changed')
    print(json.dumps(dict(status='verified', file_count=len(files),
                          bytes=sum(x['size'] for x in files), exe_sha256=EXPECTED_EXE), indent=2))


if __name__ == '__main__':
    main()
