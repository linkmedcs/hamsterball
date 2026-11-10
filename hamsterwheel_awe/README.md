# Hamsterwheel Awe

从 `hxgame4.2.exe` 提取的仓鼠球安卓移植工程，目标是逐步还原原版关卡与玩法。

当前为 **0.1 开发预览版**：已经能在 Android 上加载原版场景、显示仓鼠与球，并使用触屏摇杆进行基础滚球操作。还不是完整还原版，后期赛道的移动平台与机关尚未接入，不能据此认为所有赛道均可通关。

## 目录

| 目录 | 内容 |
| --- | --- |
| `original/hamsterball/` | 4.2 合集中完整的 546 个仓鼠球原始文件，包括 Windows EXE、DLL、音乐及数据 |
| `original/installer/` | 4.2 安装包的完整解包内容，包含 CAB、HDR 和安装引擎 |
| `original/manifest.json` | 原安装包 SHA-256 与全部游戏文件的大小、SHA-256 |
| `android/` | Java / OpenGL ES 2.0 原生安卓工程，可用 Android Studio 导入 |
| `android/app/src/main/assets/` | 转换后的 86 个场景、33 个模型、原版贴图和音效、15 关配置 |
| `tools/` | 原始资源解析、转换、校验、离线 APK 构建和模拟器检查工具 |
| `docs/` | 格式说明、校验结果、开发路线与模拟器截图 |
| `dist/hamsterwheel-awe-debug.apk` | 已签名的调试 APK |

## 已实现

- 原始资源完整提取，并以逐文件 SHA-256 校验保留。
- 严格解析 86 个 `.meshworld`、33 个 `.mesh` 和 100 个 `.cached` 文件，要求完整消费文件内容。
- 15 条原版赛道的静态几何、材质、纹理、出生点、安全点和计时参数。
- 原版仓鼠模型与透明球、跟随镜头、球旋转显示。
- 固定 120 Hz 的基础球体与三角形碰撞、重力、加速、限速、跌落复位。
- 触屏摇杆、右侧拖动旋转镜头、暂停、重新开始、关卡选择。
- 根据原始 `N:GOAL` 材质检测终点与单关倒计时结束。

## 当前边界

- 物理参数为新实现，尚未通过原版运行轨迹反推；操控手感不保证与原版一致。
- 移动平台、齿轮、弹射器、敌人、破碎效果与机关逻辑尚未实现。目前只显示赛道静态部分。
- `E:` 事件区域的语义尚未逐项还原；目前不绘制，也不作为普通实体碰撞。
- 音效已转换整理但尚未播放。MO3 原版音乐保存在 `original/`，尚未接入安卓音乐播放器。
- 暂未实现原版主菜单、赛事时间池、奖牌、解锁、存档、镜像赛与多人模式。
- 渲染采用简化光照、透明材质和自由镜头；尚未还原原版镜头曲线及全部材质效果。
- 当前只有模拟器验证，尚无 Android 真机测试。调试 APK 不能作为正式发行包。

## 构建

默认使用本机安装的 Android SDK 与 Android Studio 自带 JDK，不需要下载依赖：

```sh
cd hamsterwheel_awe
python3 tools/build_debug.py
```

脚本支持 `ANDROID_SDK_ROOT`（或 `ANDROID_HOME`）和 `JAVA_HOME` 环境变量。
默认 SDK 路径为 `~/Library/Android/sdk`，JDK 路径为 `/Applications/Android Studio.app/Contents/jbr/Contents/Home`。
目标 SDK 36，最低 Android 8.0（API 26）。

也可在 Android Studio 中打开 `android/`。该路径使用 Android Gradle Plugin 8.13.0，需要 Gradle 8.13 或兼容版本及相应网络依赖；本次验证使用的是上面的离线构建脚本。

## 操作

- 左下摇杆：移动仓鼠球。
- 右侧拖动：旋转镜头。
- `Courses`：选择关卡，当前为开发预览，全部开放。
- `Restart`：重新开始当前关卡。
- `Pause / Resume`：暂停、继续。

## 校验

```sh
python3 tools/validate_assets.py
```

资源校验包括原始文件哈希、格式边界、贴图引用、生成文件长度与有限浮点数检查。
另外有 70 个关卡场景同时包含缓存，转换后的三角形数量与缓存中的三角形数量全部一致。
`tools/PhysicsChecks.java` 对实际安卓物理实现检查地面接触、输入加速、速度上限、跌落复位、终点与计时结束。
模拟器检查脚本 `tools/smoke_android.py` 仅针对明确命名的模拟器运行，不会自动操作真机。

本次在 API 36.1 ARM64 模拟器中成功安装并启动 APK，全部 15 条主赛道均通过加载检查；第一关触屏移动日志确认了加速与稳定地面接触。检查记录见 `docs/android-course-smoke.json` 和 `docs/android-control-smoke.log`，画面见 `docs/android-preview.png`。加载检查不包含各关卡通关验证。

Windows 原程序与资源属于原始游戏内容；此工程保留原始说明与许可文本，尚未取得任何发行授权。
