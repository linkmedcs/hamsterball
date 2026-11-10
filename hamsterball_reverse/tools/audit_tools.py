#!/usr/bin/env python3
"""Read-only tool inventory. Does not start ADB, Wine, or virtual machines."""
import json
import platform
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from wine_runtime import discover_wine, WineRuntimeError

ROOT = Path(__file__).resolve().parents[1]


def version(executable, *args):
    if not executable or not Path(executable).exists():
        return None
    try:
        result = subprocess.run([str(executable), *args], capture_output=True, text=True, timeout=15)
        return dict(path=str(executable), exit_code=result.returncode,
                    output=(result.stdout + result.stderr).strip()[:1800])
    except (OSError, subprocess.TimeoutExpired) as e:
        return dict(path=str(executable), error=str(e))


def main():
    sdk = Path.home() / 'Library/Android/sdk'
    try:
        wine = discover_wine()
    except WineRuntimeError as error:
        wine = dict(error=str(error))
    jdk = Path('/opt/homebrew/opt/openjdk/libexec/openjdk.jdk/Contents/Home')
    report = dict(created_utc=datetime.now(timezone.utc).isoformat(),
                  host=dict(system=platform.system(), machine=platform.machine(),
                            mac_version=platform.mac_ver()[0], python=platform.python_version()),
                  tools={name: version(shutil.which(name), '--version')
                         for name in ['clang++', 'cmake', 'ninja', 'objdump', 'python3']},
                  jdk=version(jdk / 'bin/java', '-version'),
                  android_studio_jdk=version('/Applications/Android Studio.app/Contents/jbr/Contents/Home/bin/java', '-version'),
                  android=dict(sdk=str(sdk), platforms=[p.name for p in (sdk/'platforms').glob('*')],
                               build_tools=[p.name for p in (sdk/'build-tools').glob('*')],
                               ndk=[p.name for p in (sdk/'ndk').glob('*')],
                               cmake=[p.name for p in (sdk/'cmake').glob('*')],
                               adb=version(sdk/'platform-tools/adb', 'version')),
                  ghidra=[str(p.relative_to(ROOT)) for p in (ROOT/'toolchain').glob('ghidra_*/support/analyzeHeadless')],
                  windows_runtime=dict(discovery=wine,
                                       note='Candidate only: actual game launch must be recorded separately; use a new WINEPREFIX.',
                                       path_tools={n: shutil.which(n) for n in ['wine', 'wine64', 'prlctl', 'VBoxManage', 'qemu-system-x86_64']},
                                       applications=[p.name for p in Path('/Applications').iterdir()
                                                     if any(s in p.name.lower() for s in ['utm', 'parallels', 'vmware', 'virtualbox', 'crossover'])]))
    (ROOT/'analysis/tool-inventory.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
