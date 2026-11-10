#!/usr/bin/env python3
"""Install only on a named emulator; capture preview or check all course loads."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
SDK = Path(os.environ.get('ANDROID_SDK_ROOT', str(Path.home()/'Library/Android/sdk')))
parser = argparse.ArgumentParser()
parser.add_argument('--serial', default='emulator-5554')
parser.add_argument('--port', default='5038')
parser.add_argument('--all-courses', action='store_true')
parser.add_argument('--courses', help='Comma-separated zero-based course indices to recheck')
args = parser.parse_args()
if not args.serial.startswith('emulator-'):
    parser.error('This smoke check only targets an emulator.')


def adb(*command):
    return subprocess.check_output([str(SDK/'platform-tools/adb'), '-P', args.port,
                                    '-s', args.serial, *command], stderr=subprocess.STDOUT).decode().strip()


def launch(index):
    adb('shell', 'am', 'force-stop', 'com.hamsterwheel.awe')
    adb('logcat', '-c')
    adb('shell', 'am', 'start', '-n', 'com.hamsterwheel.awe/.MainActivity',
        '--ei', 'course', str(index), '--ez', 'paused', 'true', '--ez', 'trace', 'true')
    for _ in range(60):
        time.sleep(.5)
        logs = adb('logcat', '-d', '-s', 'Hamsterwheel', 'AndroidRuntime')
        if 'FATAL EXCEPTION' in logs or 'Load error:' in logs:
            raise RuntimeError(logs)
        if 'Course loaded:' in logs:
            time.sleep(1)
            return logs
    raise RuntimeError('Course loading timed out: '+logs)


if args.all_courses or args.courses:
    races = json.loads((ROOT/'android/app/src/main/assets/races.json').read_text())
    report = ROOT/'docs/android-course-smoke.json'
    results = json.loads(report.read_text()) if args.courses and report.exists() else []
    selected = [int(x) for x in args.courses.split(',')] if args.courses else range(len(races))
    for i in selected:
        race = races[i]
        logs = launch(i)
        print(race['title'], 'loaded', flush=True)
        results = [r for r in results if r['course'] != race['id']]
        results.append(dict(course=race['id'], loaded=True, log=logs))
        report.write_text(json.dumps(results, indent=2))
else:
    print(adb('install', '--no-incremental', '-r', str(ROOT/'dist/hamsterwheel-awe-debug.apk')), flush=True)
    launch(0)
    time.sleep(2)
    adb('shell', 'input', 'tap', '2270', '60')
    adb('shell', 'input', 'swipe', '200', '880', '280', '880', '1800')
    time.sleep(.5)
    logs = adb('logcat', '-d', '-s', 'Hamsterwheel', 'AndroidRuntime')
    (ROOT/'docs/android-control-smoke.log').write_text(logs)
    adb('shell', 'screencap', '-p', '/sdcard/hamsterwheel-preview.png')
    adb('pull', '/sdcard/hamsterwheel-preview.png', str(ROOT/'docs/android-preview.png'))
    print(logs)
