# Hamsterball reverse engineering and Android port research

目标：研究原版 Windows EXE，逐步验证并移植游戏逻辑到 Android。

- `hamsterball_reverse/`：当前逆向研究、验证工具和证据；第一阶段仍未完成。
- `hamsterwheel_awe/`：早期 Android 近似实现及资源转换工具，不代表忠实移植。

目前尚无完成原版玩法还原的 Android 版本。Mac 上的原版参考运行通过 Wine 执行 Windows EXE。

本仓库保留源码、文档、分析结果和原始文件哈希；原版安装包、游戏资源（包括生成的 Android assets）、运行环境、Ghidra 数据库及大型日志仅保留本地，不随 Git 上传。因此克隆仓库后需要自行提供匹配的原版文件，具体步骤见各项目文档。
