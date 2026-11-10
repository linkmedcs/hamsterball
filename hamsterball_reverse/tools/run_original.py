#!/usr/bin/env python3
"""Run a disposable game copy in a dedicated prefix, never another app's prefix."""
import argparse
import json
import os
import shutil
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path
from wine_runtime import discover_wine, WineRuntimeError

ROOT = Path(__file__).resolve().parents[1]
PREFIX = ROOT/'runtime/wine-prefix'
GAME = ROOT/'runtime/game'


def environment(runtime):
    env = dict(os.environ)
    env.update(WINEPREFIX=str(PREFIX), WINEARCH='win64', WINEDEBUG='-all,err+all',
               WINEDLLOVERRIDES='mscoree,mshtml=')
    if runtime['frameworks']:
        existing = env.get('DYLD_FALLBACK_LIBRARY_PATH')
        env['DYLD_FALLBACK_LIBRARY_PATH'] = runtime['frameworks'] + (os.pathsep + existing if existing else '')
    return env


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('action', choices=['check', 'prepare', 'boot', 'launch', 'stop'])
    parser.add_argument('--wine', help='Wine executable, bin directory, installation root or .app; overrides discovery')
    parser.add_argument('--wait', action='store_true', help='Keep supervising game until it exits')
    parser.add_argument('--graphics-debug', action='store_true', help='Enable graphics warnings and adapter diagnostics without per-draw tracing')
    args = parser.parse_args()
    subprocess.run(['python3', str(ROOT/'tools/prepare_baseline.py'), '--verify'], check=True)
    if args.action == 'prepare':
        if not GAME.exists():
            shutil.copytree(ROOT/'original/game', GAME)
        print('Working copy prepared: ' + str(GAME))
        return
    try:
        runtime = discover_wine(args.wine)
    except WineRuntimeError as error:
        parser.exit(2, str(error) + '\n')
    env = environment(runtime)
    if args.graphics_debug:
        env['WINEDEBUG'] = '-all,err+all,warn+d3d,warn+d3d8,trace+winediag'
    if args.action == 'check':
        print(json.dumps(runtime, ensure_ascii=False, indent=2), flush=True)
        try:
            result = subprocess.run([runtime['executable'], '--version'], env=env,
                                    capture_output=True, text=True, timeout=30)
        except (OSError, subprocess.TimeoutExpired) as error:
            parser.exit(2, 'Wine 自检失败：' + str(error) + '\n')
        print(result.stdout + result.stderr, end='')
        raise SystemExit(result.returncode)
    if args.action == 'stop':
        if not runtime['wineserver']:
            parser.exit(2, '未找到该 Wine 安装的 wineserver，无法停止测试前缀。\n')
        stopped = subprocess.run([runtime['wineserver'], '-k'], env=env)
        if stopped.returncode not in (0, 1):
            raise SystemExit(stopped.returncode)
        return
    if not GAME.exists():
        shutil.copytree(ROOT/'original/game', GAME)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    log_path = ROOT/'logs'/f'wine-{args.action}-{stamp}.log'
    cmd = [runtime['executable']]
    cmd += ['wineboot', '-u'] if args.action == 'boot' else ['hamsterball.exe']
    record = dict(timestamp_utc=stamp, action=args.action, command=cmd, cwd=str(GAME),
                  wine_prefix=str(PREFIX), log=str(log_path.relative_to(ROOT)),
                  compatibility_status='unverified', renderer='not yet observed')
    record['wine_runtime'] = runtime
    record['wine_debug'] = env['WINEDEBUG']
    with log_path.open('w') as log:
        process = subprocess.Popen(cmd, cwd=GAME, env=env, stdout=log, stderr=subprocess.STDOUT)
        record['pid'] = process.pid
        if args.action == 'boot':
            try:
                record['exit_code'] = process.wait(timeout=90)
            except subprocess.TimeoutExpired:
                record['status'] = 'boot_timeout_process_left_for_inspection'
        else:
            time.sleep(5)
            record['exit_code_after_5s'] = process.poll()
            record['status'] = 'process_alive_requires_visual_check' if process.poll() is None else 'process_exited'
    (ROOT/'runtime'/f'{args.action}-last.json').write_text(json.dumps(record, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps(record, ensure_ascii=False, indent=2))
    print(log_path.read_text(errors='replace')[-4000:])
    if args.action == 'launch' and args.wait and process.poll() is None:
        print('Supervising original process until exit.', flush=True)
        record['final_exit_code'] = process.wait()
        (ROOT/'runtime/launch-last.json').write_text(json.dumps(record, ensure_ascii=False, indent=2)+'\n')
        print(json.dumps(record, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
