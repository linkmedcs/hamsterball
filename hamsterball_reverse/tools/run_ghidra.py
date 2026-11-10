#!/usr/bin/env python3
"""Import or update the fixed EXE in a persistent Ghidra project."""
import argparse
import hashlib
import json
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--refresh', action='store_true', help='Re-export existing database without re-import')
    parser.add_argument('--reanalyze', action='store_true', help='Rerun analysis on existing database')
    args = parser.parse_args()
    subprocess.run(['python3', str(ROOT/'tools/prepare_baseline.py'), '--verify'], check=True)
    executable = ROOT/'original/game/hamsterball.exe'
    ghidra = sorted((ROOT/'toolchain').glob('ghidra_*/support/analyzeHeadless'))[-1]
    project_dir = ROOT/'analysis/ghidra'
    seeds = ROOT/'analysis/seeds.tsv'
    known = [
        ('0x40cd10', 'candidate_Board_ctor', 'Static Board name/vptr evidence; ABI not verified'),
        ('0x41dab0', 'candidate_InternalBeginner_Cascade_ctor', 'Internal name Beginner, but constructor selects CASCADERACE and levelcascade; not Level1'),
        ('0x414240', 'candidate_WarmUp_Level1_ctor', 'Internal Warm-Up constructor selects BEGINNERRACE; Level1 loader at 0x414310'),
        ('0x414310', 'candidate_Level1_load', 'Passes levels\\level1 to 0x46c8c0; static mapping, not runtime verified'),
        ('0x4627d0', 'probe_Motion_ctor', 'Original isolated probe executed; object in ESI, context in EAX'),
        ('0x4630e0', 'probe_Motion_reset', 'Original isolated constructor calls this; field semantics provisional'),
        ('0x4014b0', 'probe_SetDirectionScale', '100 original isolated cases; object EAX and one stack scalar'),
        ('0x463200', 'probe_EllipsoidMove', 'Only empty-world cases executed; collision unverified'),
        ('0x40dce6', 'anchor_CameraLocus_reference', 'Instruction passes CAMERALOCUS to 0x4716b0'),
        ('0x413867', 'anchor_Goal_reference', 'N:GOAL string reference; event semantics unverified'),
    ]
    seen = {int(x[0], 16) for x in known}
    boards = json.loads((ROOT/'analysis/inherited/board-map.json').read_text())
    for internal_name, prefix in [('Board (Warm-Up)', 'Level1'), ('Board (Beginner)', 'Cascade')]:
        board = next(x for x in boards if x['name']==internal_name)
        for i, address in enumerate(board['method_candidates']):
            if int(address, 16) not in seen:
                known.append((address, f'candidate_{prefix}_vslot_{i:02d}', f'{internal_name} vtable +0x{i*4:x}; role unverified; table end heuristic'))
                seen.add(int(address, 16))
    seeds.write_text('address\tlabel\tevidence\n'+'\n'.join('\t'.join(x) for x in known)+'\n')
    name = 'Hamsterball_4_2'
    if (project_dir/(name+'.gpr')).exists() and not (args.refresh or args.reanalyze):
        raise SystemExit('Database exists. Use --refresh to export; do not overwrite analysis.')
    cmd = [str(ghidra), str(project_dir), name]
    if args.refresh or args.reanalyze:
        cmd += ['-process', 'hamsterball.exe']
        cmd += ['-analysisTimeoutPerFile', '900'] if args.reanalyze else ['-noanalysis']
    else:
        cmd += ['-import', str(executable), '-analysisTimeoutPerFile', '900']
    cmd += ['-scriptPath', str(ROOT/'tools/ghidra_scripts'), '-postScript', 'ExportHamsterball.java',
            str(ROOT/'analysis/exports'), str(seeds), '-log', str(ROOT/'logs/ghidra-analysis.log'),
            '-scriptlog', str(ROOT/'logs/ghidra-script.log'), '-max-cpu', '4']
    env = dict(os.environ)
    env['JAVA_HOME'] = '/opt/homebrew/opt/openjdk/libexec/openjdk.jdk/Contents/Home'
    # Ghidra and Java caches/settings stay inside this new workspace.
    java_home = ROOT/'toolchain/java-user'
    java_home.mkdir(exist_ok=True)
    env['JAVA_TOOL_OPTIONS'] = env.get('JAVA_TOOL_OPTIONS', '') + ' -Duser.home=' + str(java_home)
    (ROOT/'analysis/ghidra-command.json').write_text(json.dumps(dict(command=cmd, java_home=env['JAVA_HOME'],
        java_tool_options=env['JAVA_TOOL_OPTIONS'], exe_sha256=hashlib.sha256(executable.read_bytes()).hexdigest()), indent=2)+'\n')
    with (ROOT/'logs/ghidra-console.log').open('w') as log:
        result = subprocess.run(cmd, env=env, stdout=log, stderr=subprocess.STDOUT)
    print((ROOT/'logs/ghidra-console.log').read_text()[-1800:])
    if result.returncode:
        raise SystemExit(result.returncode)
    if 'HAMSTERBALL_EXPORT_OK' not in (ROOT/'logs/ghidra-console.log').read_text():
        raise SystemExit('Ghidra process ended without a successful export; inspect logs')
    output_files = sorted((ROOT/'analysis/exports').glob('*'))
    record = dict(executable_sha256=hashlib.sha256(executable.read_bytes()).hexdigest(),
                  export_status='completed',
                  files=[dict(path=str(p.relative_to(ROOT)), sha256=hashlib.sha256(p.read_bytes()).hexdigest())
                         for p in output_files if p.is_file()])
    (ROOT/'analysis/export-manifest.json').write_text(json.dumps(record,indent=2)+'\n')


if __name__ == '__main__':
    main()
