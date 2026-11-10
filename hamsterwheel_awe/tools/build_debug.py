#!/usr/bin/env python3
"""Offline debug APK build using only the installed Android SDK and JDK."""
from pathlib import Path
import os
import shutil
import subprocess
import sys
import zipfile

ROOT = Path(__file__).resolve().parents[1]
SDK = Path(os.environ.get('ANDROID_SDK_ROOT', os.environ.get('ANDROID_HOME', str(Path.home()/'Library/Android/sdk'))))
JAVA = Path(os.environ.get('JAVA_HOME', '/Applications/Android Studio.app/Contents/jbr/Contents/Home'))
BUILD = ROOT / '.build'
SRC = ROOT / 'android/app/src/main'


def run(args):
    environment = dict(os.environ, JAVA_HOME=str(JAVA))
    subprocess.run([str(a) for a in args], check=True, env=environment, cwd=ROOT)


def main():
    sdk_versions = sorted((SDK/'platforms').glob('android-*'), key=lambda p:int(p.name.split('-')[1]))
    tools = sorted((SDK/'build-tools').iterdir(), key=lambda p:tuple(int(x) for x in p.name.split('.')))
    if not sdk_versions or not tools:
        sys.exit('Install Android SDK platform 36 and build-tools first.')
    android = sdk_versions[-1]/'android.jar'
    bt = tools[-1]
    for folder in ('classes', 'generated', 'dex'):
        destination = BUILD/folder
        if destination.exists():
            shutil.rmtree(destination)
        destination.mkdir(parents=True)
    run([sys.executable, ROOT/'tools/prepare_assets.py'])
    manifest = (SRC/'AndroidManifest.xml').read_text().replace('<manifest ', '<manifest package="com.hamsterwheel.awe" ', 1)
    (BUILD/'AndroidManifest.xml').write_text(manifest)
    run([bt/'aapt2', 'compile', '--dir', SRC/'res', '-o', BUILD/'resources.zip'])
    run([bt/'aapt2', 'link', '-o', BUILD/'unsigned.apk', '-I', android,
         '--manifest', BUILD/'AndroidManifest.xml', '--java', BUILD/'generated',
         '--min-sdk-version', '26', '--target-sdk-version', '36',
         '--version-code', '1', '--version-name', '0.1.0',
         '-A', SRC/'assets', BUILD/'resources.zip'])
    java_files = list((SRC/'java').rglob('*.java')) + list((BUILD/'generated').rglob('*.java'))
    run([JAVA/'bin/javac', '-encoding', 'UTF-8', '-source', '8', '-target', '8',
         '-classpath', android, '-d', BUILD/'classes'] + java_files)
    run([JAVA/'bin/jar', 'cf', BUILD/'classes.jar', '-C', BUILD/'classes', '.'])
    run([bt/'d8', '--min-api', '26', '--lib', android, '--output', BUILD/'dex', BUILD/'classes.jar'])
    with zipfile.ZipFile(BUILD/'unsigned.apk', 'a', zipfile.ZIP_DEFLATED) as apk:
        for dex in (BUILD/'dex').glob('*.dex'):
            apk.write(dex, dex.name)
    run([bt/'zipalign', '-f', '4', BUILD/'unsigned.apk', BUILD/'aligned.apk'])
    key = BUILD/'debug.keystore'
    if not key.exists():
        run([JAVA/'bin/keytool', '-genkeypair', '-keystore', key, '-storepass', 'android',
             '-keypass', 'android', '-alias', 'androiddebugkey', '-keyalg', 'RSA',
             '-validity', '10000', '-dname', 'CN=Android Debug,O=Android,C=US'])
    output = ROOT/'dist/hamsterwheel-awe-debug.apk'
    output.parent.mkdir(exist_ok=True)
    run([bt/'apksigner', 'sign', '--ks', key, '--ks-pass', 'pass:android',
         '--key-pass', 'pass:android', '--out', output, BUILD/'aligned.apk'])
    run([bt/'apksigner', 'verify', '--verbose', output])
    print(f'Built {output} ({output.stat().st_size:,} bytes)')


if __name__ == '__main__':
    main()
