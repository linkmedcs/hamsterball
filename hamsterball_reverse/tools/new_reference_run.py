#!/usr/bin/env python3
"""Create an explicitly UNCAPTURED original-game reference session."""
import argparse
import hashlib
import json
import re
import shutil
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('name', help='Lowercase letters, numbers, hyphens; never an arbitrary path')
    args = parser.parse_args()
    if not re.fullmatch(r'[a-z0-9][a-z0-9-]{0,63}', args.name):
        parser.error('Invalid session name')
    lock = ROOT/'original/baseline-lock.json'
    baseline = json.loads(lock.read_text())
    folder = ROOT/'reference/runs'/args.name
    folder.mkdir(exist_ok=False)
    shutil.copy2(lock, folder/'baseline-lock.json')
    record = dict(schema_version=1, run_name=args.name, capture_status='not_started',
                  created_utc=datetime.now(timezone.utc).isoformat(),
                  executable_sha256=baseline['executable_sha256'],
                  baseline_lock_sha256=hashlib.sha256(lock.read_bytes()).hexdigest(),
                  course=dict(resource='Levels/Level1.MESHWORLD', race_key='BEGINNERRACE',
                              internal_class='Board (Warm-Up)', mirror=False),
                  runtime=dict(kind=None, version=None, os=None, cpu=None, gpu=None,
                               renderer=None, resolution=None, fullscreen=None, refresh_hz=None),
                  configuration=dict(difficulty=None, control_device=None, sensitivity=None,
                                     save_snapshot_sha256=None, registry_snapshot_sha256=None),
                  initial_state=dict(checkpoint=None, position=None, velocity=None, camera=None,
                                     rng_state=None, logic_step=None, logical_time=None),
                  timing=dict(logic_dt=None, units=None, input_time_domain=None, video_fps=None),
                  evidence=dict(video=None, audio=None, inputs=None, state_trace=None, event_trace=None),
                  repeats=[], unavailable_fields=[], differences=[],
                  notes=['Template only. No gameplay recording or deterministic replay has occurred.',
                         'OS input timestamps alone do not prove when the game consumed inputs.'])
    (folder/'session.json').write_text(json.dumps(record,ensure_ascii=False,indent=2)+'\n')
    print(folder.resolve())


if __name__ == '__main__':
    main()
