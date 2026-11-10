#!/usr/bin/env python3
"""Preserve startup evidence, not a gameplay reference or deterministic replay."""
import hashlib
import json
import re
import shutil
from datetime import datetime, timezone
from pathlib import Path
from prepare_baseline import inventory

ROOT = Path(__file__).resolve().parents[1]


def main():
    folder = ROOT/'reference/runtime-assessment'
    folder.mkdir(exist_ok=True)
    evidence = []
    for path in sorted((ROOT/'logs').glob('wine-*.log')):
        dst = folder/path.name
        shutil.copy2(path, dst)
        evidence.append(dict(path=dst.relative_to(ROOT).as_posix(), sha256=hashlib.sha256(dst.read_bytes()).hexdigest()))
    for path in (ROOT/'runtime').glob('*-last.json'):
        shutil.copy2(path, folder/path.name)
    registry = ROOT/'runtime/wine-prefix/user.reg'
    if registry.exists():
        blocks = re.split(r'\n(?=\[)', registry.read_text(errors='replace'))
        game_blocks = [b for b in blocks if 'Raptisoft' in b.splitlines()[0] and 'Hamsterball' in b.splitlines()[0]]
        text = '\n\n'.join(game_blocks)+'\n'
        (folder/'hamsterball-only.wine-reg.txt').write_text(text)
        evidence.append(dict(path=(folder/'hamsterball-only.wine-reg.txt').relative_to(ROOT).as_posix(),
                             sha256=hashlib.sha256(text.encode()).hexdigest()))
    frozen = json.loads((ROOT/'original/baseline-lock.json').read_text())
    current = inventory(ROOT/'runtime/game')
    (folder/'working-copy-manifest.json').write_text(json.dumps(current,indent=2)+'\n')
    want = {x['path']:x for x in frozen['files']}
    got = {x['path']:x for x in current}
    changes = [k for k in sorted(want.keys() | got.keys()) if want.get(k) != got.get(k)]
    report = dict(created_utc=datetime.now(timezone.utc).isoformat(), status='partial_startup_only',
                  original_reference_captured=False, wine_version='wine-8.0.1 (WineskinCX 23.6.0)',
                  prefix='runtime/wine-prefix', game_copy='runtime/game',
                  initialization_exit_code=0, game_process_observed_alive=True,
                  windows_registry_branch_observed='HKCU/Software/Raptisoft/Hamsterball',
                  changed_working_game_files=changes, evidence=evidence,
                  observations=['Original process started in experimental wow64 mode.',
                                'Graphics log reports MoltenVK initialization and display-mode changes returning -2.',
                                'Standalone Wine preloader could not be bound by the available app UI interface.',
                                'No menu/first-course picture, input response or audio was verified.',
                                'Dedicated Wine server stopped after inspection; final process exit code is not an organic crash diagnosis.'],
                  missing=['Stable visible first-course session', 'Input and video capture',
                           'Verified logical update timing', 'Observed initial physical/camera/random state',
                           'Repeated identical-input runs'],
                  next_runtime_actions=['Resolve Wine window/display observation; try an isolated virtual desktop or windowed mode with logged settings.',
                                        'If still unreliable, establish a native Windows baseline on a real machine or suitable VM.'])
    (folder/'assessment.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'], changed_files=changes,
                          evidence_count=len(evidence), original_reference_captured=False),indent=2))


if __name__ == '__main__':
    main()
