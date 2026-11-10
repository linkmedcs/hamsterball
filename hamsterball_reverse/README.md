# Hamsterball 原 EXE 逆向工作区

本目录于 2026-11-08 新建，开始执行 [移植计划](../hamsterwheel_awe/docs/ROADMAP.md) 的第一阶段。当前状态为 **第一阶段进行中**：原始基准与反编译环境已建立，原版完整运行和确定性采集尚未通过。

当前结果与下一步见 [第一阶段记录](docs/STAGE1_STATUS.md)。

## 已有产物

| 路径 | 用途 |
| --- | --- |
| `original/game/` | 独立复制的原版 546 文件，约 26.1 MiB；不在此目录启动游戏 |
| `original/baseline-lock.json` | 原包、EXE、资源、配置及继承证据的哈希 |
| `toolchain/` | 官方 Ghidra 12.2、下载校验、Mac ARM64 反编译器编译记录 |
| `analysis/ghidra/Hamsterball_4_2.gpr` | 持久 Ghidra 工程入口，可继续注释／研究 |
| `analysis/exports/` | 关键函数伪代码、反汇编、引用、函数索引与入口解析结果 |
| `analysis/level1-static.json` | 第一关几何、标记、相机轨迹和配置的静态解析 |
| `analysis/course-mapping-evidence.asm` | Level1 与 Cascade 映射证据 |
| `analysis/inherited/` | 前期研究快照；其中脚本路径按旧工作区编写，不直接运行 |
| `reference/` | 基准用例、未采集会话模板、实际 Wine 启动评估证据 |
| `runtime/` | 可变的游戏副本与独立 Wine 前缀 |
| `docs/FIELD_LAYOUT.md` | 字段、寄存器传参约定与置信度初表 |
| `docs/REFERENCE_PROTOCOL.md` | 第一关输入、画面、配置和状态采集规范 |

## 复现命令

在本目录执行：

```sh
python3 tools/prepare_baseline.py --verify
python3 tools/audit_tools.py
python3 tools/extract_level1.py
python3 tools/run_ghidra.py --refresh
python3 tools/validate_stage1.py
```

首次导入用 `python3 tools/run_ghidra.py`；已有工程重新分析用 `--reanalyze`。`--refresh` 重新导出并保留工程，不重新导入 EXE。Ghidra 使用本机 OpenJDK 27；用户配置缓存放在本目录。更换机器时检查脚本中的 JDK 路径。

官方发行包未附 Mac ARM64 反编译器，本工作区已通过 `python3 tools/build_ghidra_native.py` 编译包内官方源码。源码未修改，架构通过 make 参数指定。安装包、原 EXE 及游戏资源均未打补丁。

启动评估工具：

```sh
python3 tools/run_original.py prepare
python3 tools/run_original.py check
python3 tools/run_original.py boot
python3 tools/run_original.py launch --wait
python3 tools/run_original.py stop
```

脚本优先使用项目内 `toolchain/wineskin-runtime/` 的运行时，然后检查 PATH 和应用目录。可用 `--wine /绝对路径/bin/wine64` 或环境变量 `HAMSTERBALL_WINE` 显式指定，显式路径无效时会报错。先用 `check` 查看选中路径并运行版本自检；这不启动游戏。`launch` 可能显示窗口，不能因进程存活就认定运行正常。Wine 前缀仅为本工作区的 `runtime/wine-prefix`，不使用其他游戏的前缀。

2026-11-09 修复：此前绑定另一个应用的固定 Wine 路径已失效，导致 `Wine candidate missing`。已从本机保留镜像复制相同版 Wine 和配套 Frameworks 到本项目，不复制其他游戏或其前缀，来源记录在 `toolchain/wineskin-runtime/provenance.json`。现在启动不再依赖那个应用仍位于 `/Applications`。

### D3DERR_NOTAVAILABLE 启动错误

本机全屏显示模式切换失败。已在测试前缀内设置 `Fullscreen` 为单字节二进制 `00`、分辨率为 1024×768；窗口模式下的诊断已进入持续绘制和 Present 调用。无需重复配置，正常测试运行 `python3 tools/run_original.py launch --wait`。画面、输入、音频与第一关可玩性仍需实际确认。

如要在新前缀重新应用该设置，可执行 `python3 tools/configure_graphics.py windowed`；此命令会停止本项目测试进程、导出原游戏显示配置，再应用窗口模式。每次修改的证据在 `reference/graphics-tests/`。`windowed-gl` 可另行强制应用程序的 OpenGL 后端，本次未使用该配置。`--graphics-debug` 仅增加警告／适配器日志，避免逐次绘制跟踪造成大量日志。

## 已知边界

反编译器输出是辅助分析结果，不是原工程源码。自动识别的函数数不等于已恢复玩法函数数，44 个导出也不等于 44 个函数已验证。现有安卓预览仍在 `hamsterwheel_awe` 中，本目录目前没有新的原版还原 APK。

第一关的内部名为 `Board (Warm-Up)`；名为 `Board (Beginner)` 的类实际选择 Cascade，详见阶段记录。后续以资源、配置和代码调用链判断关卡身份。
