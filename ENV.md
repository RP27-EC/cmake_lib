# 环境记录（ENV.md）

T1.1 验收产物。生成日期：2026-11-05。**以下数值全部为本机命令真实输出**，不是手抄。

## 1. 主机

| 项 | 值 | 采集命令 |
| --- | --- | --- |
| 系统 | Ubuntu 22.04.5 LTS（原生双系统，非 WSL/虚拟机） | `lsb_release -ds` |
| 架构 | x86_64 | `uname -m` |
| CPU 核数 | 32 | `nproc` |
| 内存 | 14 GiB（可用 8.9 GiB） | `free -h` |
| 根分区 | 246 G，已用 57 G，可用 176 G | `df -h /` |

## 2. 主机工具

| 工具 | 版本 | 要求（Zephyr 3.7） | 结论 |
| --- | --- | --- | --- |
| cmake | 3.22.1 | ≥3.20.5 | ✓ |
| ninja | 1.10.1 | — | ✓ |
| dtc | 1.6.1 | ≥1.4.6 | ✓ |
| gcc（主机） | 11.4.0 | — | ✓ |
| python3 | 3.10.12 | ≥3.10 | ✓ |
| gperf / ccache / dfu-util | 3.1 / 4.5.1 / 0.9 | — | ✓ |

## 3. Zephyr 工作区

| 项 | 值 |
| --- | --- |
| 工作区 | `/home/hqz/zephyrproject` |
| venv | `/home/hqz/zephyrproject/.venv`（Python 3.10.12） |
| west 版本 | v1.5.0 |
| zephyr 版本 | **v3.7.0**（`git describe --tags`） |
| west list 的 revision | `HEAD`（manifest 仓库自身显示 HEAD 属正常，版本以 `git describe --tags` 为准） |
| Zephyr SDK | **0.16.8**，路径 `/home/hqz/zephyr-sdk-0.16.8` |
| 工具链 | `arm-zephyr-eabi-gcc 12.2.0` |
| CMake 包注册 | `west zephyr-export` 已执行（`~/.cmake/packages/`） |
| Python 依赖 | `zephyr/scripts/requirements.txt` 已装（`elftools/pykwalify/can/intelhex` 导入通过） |

> 注意：`pip` 直连 PyPI 时出现 SSL 断连，改用镜像 `https://pypi.tuna.tsinghua.edu.cn/simple` 后成功。

## 4. 首次构建与运行（qemu_cortex_m3）

```bash
cd ~/zephyrproject/zephyr
west build -p always -b qemu_cortex_m3 samples/hello_world
west build -t run
```

真实输出：

```text
*** Booting Zephyr OS build v3.7.0 ***
Hello World! qemu_cortex_m3/ti_lm3s6965
```

- 板卡目标打印为 `qemu_cortex_m3/ti_lm3s6965`：3.7 起 `CONFIG_BOARD_TARGET` 会带上 SoC 限定名。
- 构建统计：FLASH 7914 B / 256 KB（3.02%），RAM 4 KB / 64 KB（6.25%）。

## 5. 四个构建产物

| 文件 | 大小 | 是什么 |
| --- | --- | --- |
| `build/zephyr/zephyr.elf` | 308 K | 最终可执行固件（带符号，可调试） |
| `build/zephyr/zephyr.map` | 195 K | 链接器 map：每个符号落在哪个段、什么地址 |
| `build/zephyr/.config` | 27 K | Kconfig 最终展开结果（谁打开/关掉了哪个功能） |
| `build/zephyr/zephyr.dts` | 3.9 K | 合并后的最终设备树（板子 + SoC + overlay 的结果） |

`arm-zephyr-eabi-size`：

```text
   text    data     bss     dec     hex
   7516     398    4038   11952    2eb0
```

## 6. 代码放哪 / 怎么构建（已实测）

| 用途 | 目录 | 构建方式 |
| --- | --- | --- |
| 纯 CMake 小库（T1.3～T1.4） | `w1/t1.3-cmake-lib/` | `cmake -S . -B build -G Ninja && cmake --build build`（主机程序，与 Zephyr 无关） |
| Zephyr 应用（W2 起） | `w2/<task>/`、`w3/<task>/`… | `cd <应用目录> && west build -b qemu_cortex_m3 .`，运行 `west build -t run` |
| IDE 索引 | 每个应用目录 | `west build -b qemu_cortex_m3 . -- -DCMAKE_EXPORT_COMPILE_COMMANDS=ON` 生成 `build/compile_commands.json` |

学习仓库真实位置：`/home/hqz/zephyrproject/apps/embedded-study`，软链接 `/home/hqz/embedded-study` 指向它。
放进 `~/zephyrproject/apps/` 的原因：`west build` 需要能从当前目录向上找到 `.west` 工作区，放在工作区外会报 "not in a west workspace"；而 `apps/` 不属于 zephyr 仓库，仍是独立 git 仓库。

实测样例：`w1/t1.1-oot-hello/`（hello_world 的 out-of-tree 副本，改了一行输出），已构建并运行通过，输出 `Zephyr 起来了：qemu_cortex_m3/ti_lm3s6965`。

## 7. 未做/待办

- 未接任何真实硬件；未烧录。C 板移植推迟到 W5+（上游无 board 定义）。
- 未执行 `sudo usermod -aG dialout $USER`（当前用户不在 dialout 组，接板前必须做并重新登录）。
- 未安装 udev 规则副本（`60-openocd.rules`），接板前补。
- Zephyr SDK 解压了全部工具链（约 7.4 G），实际只用 `arm-zephyr-eabi`；空间紧张时可删其余目录。
