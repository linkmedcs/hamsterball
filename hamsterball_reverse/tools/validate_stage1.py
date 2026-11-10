#!/usr/bin/env python3
"""Validate collected evidence integrity; never equate it with game fidelity."""
import csv
import hashlib
import json
import subprocess
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    subprocess.run(['python3', str(ROOT/'tools/prepare_baseline.py'), '--verify'], check=True)
    checks = ['546 original game files and inherited evidence match frozen manifest']
    exports = json.loads((ROOT/'analysis/export-manifest.json').read_text())
    for item in exports['files']:
        p = ROOT/item['path']
        assert hashlib.sha256(p.read_bytes()).hexdigest() == item['sha256'], str(p)
    checks.append(f"{len(exports['files'])} exported files match export manifest")
    rows = list(csv.DictReader((ROOT/'analysis/exports/seed-resolution.tsv').open(), delimiter='\t'))
    assert rows
    for row in rows:
        assert row['resolved_function'], row
        assert row['decompile_status'] in ['completed_unreviewed', 'already_exported'], row
        assert (ROOT/'analysis/exports'/(row['resolved_function']+'.c')).exists(), row
    checks.append(f'{len(rows)} evidence seeds resolved, decompiler outputs available (not semantically validated)')
    summary = dict(line.split('=',1) for line in (ROOT/'analysis/exports/analysis-summary.txt').read_text().splitlines() if '=' in line)
    functions = list(csv.DictReader((ROOT/'analysis/exports/functions.tsv').open(),delimiter='\t'))
    assert len(functions) == int(summary['analyzer_function_count'])
    checks.append(f'{len(functions)} analyzer function records consistent with summary')
    level = json.loads((ROOT/'analysis/level1-static.json').read_text())
    assert level['course']['strings']['0x50d66c'] == 'levels\\level1'
    assert level['course']['strings']['0x50d64c'] == 'BEGINNERRACE'
    assert level['misleading_internal_name']['strings']['0x50e2e8'] == 'levels\\levelcascade'
    assert level['geometry']['triangle_count'] == level['geometry']['cache_triangle_count'] == 5485
    checks.append('Level1/Cascade mapping evidence and Level1 world/cache triangle counts consistent')
    native = json.loads((ROOT/'toolchain/native-build.json').read_text())
    assert hashlib.sha256((ROOT/native['binary']).read_bytes()).hexdigest() == native['sha256']
    checks.append('Locally built ARM64 decompiler matches recorded binary hash')
    for p in (ROOT/'tools').glob('*.py'):
        compile(p.read_text(), str(p), 'exec')
    checks.append('Workspace Python scripts compile')
    for p in (ROOT/'reference/runs').glob('*/session.json'):
        session = json.loads(p.read_text())
        if session['capture_status'] == 'not_started':
            assert not any(session['evidence'].values()), str(p)
    checks.append('Uncaptured reference session does not claim gameplay evidence')
    report = dict(created_utc=datetime.now(timezone.utc).isoformat(), integrity_status='passed',
                  stage1_complete=False, original_runtime_reference_verified=False,
                  checks=checks, limitations=['No original first-course gameplay capture or deterministic replay.',
                                             'Decompiled types, inferred ABIs and gameplay semantics remain provisional.',
                                             'No Android NDK installed; no original C++ gameplay core built.'])
    (ROOT/'analysis/validation-result.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(report,ensure_ascii=False,indent=2))


if __name__ == '__main__':
    main()
