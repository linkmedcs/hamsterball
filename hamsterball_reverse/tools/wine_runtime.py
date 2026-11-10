"""Discover a Wine installation without depending on another game's app name."""
import os
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class WineRuntimeError(RuntimeError):
    pass


def executable_path(value):
    path = Path(value).expanduser()
    if path.is_file() and os.access(path, os.X_OK):
        return path.absolute()
    if path.is_dir():
        for relative in ['bin/wine64', 'bin/wine', 'wine64', 'wine',
                         'Contents/Resources/wine/bin/wine64',
                         'Contents/Resources/wine/bin/wine',
                         'Contents/SharedSupport/wine/bin/wine64']:
            candidate = path / relative
            if candidate.is_file() and os.access(candidate, os.X_OK):
                return candidate.absolute()
    command = shutil.which(value)
    return Path(command).absolute() if command else None


def discover_wine(override=None):
    explicit = override or os.environ.get('HAMSTERBALL_WINE')
    if explicit:
        selected = executable_path(explicit)
        if selected is None:
            raise WineRuntimeError('指定的 Wine 不存在或不可执行：' + explicit)
        source = 'explicit'
    else:
        choices = [
            ('workspace', str(ROOT/'toolchain/wineskin-runtime/Contents/SharedSupport/wine/bin/wine64')),
            ('PATH', 'wine64'), ('PATH', 'wine'),
        ]
        for base in [Path('/Applications'), Path.home()/'Applications']:
            for pattern in ['*.app/Contents/SharedSupport/wine/bin/wine64',
                            'Wine*.app/Contents/Resources/wine/bin/wine64',
                            'Wine*.app/Contents/Resources/wine/bin/wine']:
                choices.extend(('application', str(p)) for p in sorted(base.glob(pattern)))
        selected = None
        for source, value in choices:
            selected = executable_path(value)
            if selected:
                break
        if selected is None:
            raise WineRuntimeError(
                '未找到 Wine 运行时，游戏尚未启动。\n'
                '可用 --wine /绝对路径/bin/wine64 或 HAMSTERBALL_WINE 指定已有运行时。\n'
                '原版基准也可在 Windows 上运行 original/game 的副本采集。')
    # Resolve symlinks when locating companion files, but invoke the selected launcher.
    locations = [selected.parent, selected.resolve().parent]
    server = next((p/'wineserver' for p in locations
                   if (p/'wineserver').is_file() and os.access(p/'wineserver', os.X_OK)), None)
    frameworks = None
    for location in locations:
        for parent in location.parents:
            if parent.name == 'Contents' and (parent/'Frameworks').is_dir():
                frameworks = parent/'Frameworks'
                break
        if frameworks:
            break
    return dict(executable=str(selected), wineserver=str(server) if server else None,
                frameworks=str(frameworks) if frameworks else None, source=source)
