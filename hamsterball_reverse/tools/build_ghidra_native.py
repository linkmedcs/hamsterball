#!/usr/bin/env python3
"""Build the official included decompiler sources for Apple ARM64."""
import hashlib
import json
import shutil
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ghidra = sorted((ROOT/'toolchain').glob('ghidra_*_PUBLIC'))[-1]
module = ghidra/'Ghidra/Features/Decompiler'
source = module/'src/decompile/cpp'
cmd = ['make', '-j4', 'ghidra_opt', 'CXX=clang++ -std=c++11',
       'ARCH_TYPE=-arch arm64', 'ADDITIONAL_FLAGS=-mmacosx-version-min=11.0 -w']
with (ROOT/'logs/ghidra-native-build.log').open('w') as log:
    result = subprocess.run(cmd, cwd=source, stdout=log, stderr=subprocess.STDOUT)
if result.returncode:
    print((ROOT/'logs/ghidra-native-build.log').read_text()[-5000:])
    raise SystemExit(result.returncode)
binary = module/'os/mac_arm_64/decompile'
binary.parent.mkdir(parents=True, exist_ok=True)
shutil.copy2(source/'ghidra_opt', binary)
binary.chmod(0o755)
record = dict(command=cmd, cwd=str(source.relative_to(ROOT)),
              binary=str(binary.relative_to(ROOT)), sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
              note='Built unmodified official release sources; command-line architecture overrides only')
(ROOT/'toolchain/native-build.json').write_text(json.dumps(record, indent=2)+'\n')
print(json.dumps(record, indent=2))
