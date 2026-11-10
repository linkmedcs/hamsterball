#!/usr/bin/env python3
"""Back up game graphics settings, then apply a reversible Wine test profile."""
import argparse
import hashlib
import json
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from run_original import environment, PREFIX, GAME
from wine_runtime import discover_wine

ROOT = Path(__file__).resolve().parents[1]
KEY_GAME = r'HKEY_CURRENT_USER\Software\Raptisoft\Hamsterball'
KEY_D3D = r'HKEY_CURRENT_USER\Software\Wine\AppDefaults\hamsterball.exe\Direct3D'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('profile', choices=['windowed', 'windowed-gl'])
    parser.add_argument('--wine')
    args = parser.parse_args()
    runtime = discover_wine(args.wine)
    env = environment(runtime)
    if not runtime['wineserver']:
        parser.error('Wine server missing; cannot safely update an active prefix')
    # Only this project's dedicated prefix is stopped.
    stopped = subprocess.run([runtime['wineserver'], '-k'], env=env)
    if stopped.returncode not in (0, 1):
        raise SystemExit('Failed to stop dedicated Wine server')
    subprocess.run([runtime['wineserver'], '-w'], env=env, check=True, timeout=30)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    folder = ROOT/'reference/graphics-tests'/stamp
    folder.mkdir(parents=True)
    def wine(*arguments):
        result = subprocess.run([runtime['executable'], *arguments], cwd=GAME, env=env,
                                capture_output=True, text=True, timeout=60)
        with (folder/'commands.log').open('a') as log:
            log.write(json.dumps(list(arguments))+'\n'+result.stdout+result.stderr+'\n')
        return result
    backups = []
    for key, name in [(KEY_GAME, 'game-before.reg'), (KEY_D3D, 'd3d-before.reg')]:
        query = wine('reg', 'query', key)
        if query.returncode == 0:
            result = wine('reg', 'export', key, str(folder/name), '/y')
            if result.returncode:
                raise SystemExit('Backup failed; no settings applied. See '+str(folder))
            backups.append(dict(key=key, existed=True, file=name))
        elif query.returncode == 1:
            backups.append(dict(key=key, existed=False))
        else:
            raise SystemExit('Registry query failed; no settings applied. See '+str(folder))
    # Fullscreen is a one-byte REG_BINARY in the original EXE, not REG_DWORD.
    text = ('Windows Registry Editor Version 5.00\r\n\r\n['+KEY_GAME+']\r\n'
            '"Fullscreen"=hex:00\r\n'
            '"Screen Width"=dword:00000400\r\n'
            '"Screen Height"=dword:00000300\r\n')
    if args.profile == 'windowed-gl':
        text += '\r\n['+KEY_D3D+']\r\n"renderer"="gl"\r\n'
    patch = folder/'apply.reg'
    patch.write_bytes(b'\xff\xfe'+text.encode('utf-16-le'))
    result = wine('reg', 'import', str(patch))
    if result.returncode:
        raise SystemExit('Registry import failed. See '+str(folder))
    for key in [KEY_GAME, KEY_D3D]:
        query = wine('reg', 'query', key)
        (folder/('game-after.txt' if key == KEY_GAME else 'd3d-after.txt')).write_text(query.stdout+query.stderr)
    # Stop the configuration host so a later launch reads committed settings.
    stopped = subprocess.run([runtime['wineserver'], '-k'], env=env)
    if stopped.returncode not in (0, 1):
        raise SystemExit('Failed to stop configuration Wine server')
    subprocess.run([runtime['wineserver'], '-w'], env=env, check=True, timeout=30)
    record = dict(profile=args.profile, prefix=str(PREFIX), runtime=runtime,
                  backups=backups, game_exe_sha256=hashlib.sha256((GAME/'hamsterball.exe').read_bytes()).hexdigest(),
                  changed_settings=['Fullscreen = binary 00', 'Screen Width = 1024', 'Screen Height = 768'],
                  note='Graphics configuration only; gameplay fidelity not verified')
    if args.profile == 'windowed-gl':
        record['changed_settings'].append('Wine AppDefaults/hamsterball.exe/Direct3D renderer = gl')
    (folder/'settings.json').write_text(json.dumps(record,ensure_ascii=False,indent=2)+'\n')
    print('Applied profile: '+args.profile+'\nBackup and evidence: '+str(folder))


if __name__ == '__main__':
    main()
