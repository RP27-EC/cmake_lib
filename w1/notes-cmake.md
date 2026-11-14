# T1.2 CMake 概念（notes-cmake.md）

目标：2 小时内，能用自己的话回答下面 5 题。**不要求长篇大论，每题 3～5 句 + 一个证据。**

> **关于官方教程的路径（重要）**
> 教程里写的 `Help/guide/tutorial/Step1` 是 **CMake 源码仓库内**的目录，你本机没有（除非自己 clone 整个 CMake 源码树）。所以教程里“去这个目录改这个文件”的步骤**全部跳过**，不是你没找对地方。
>
> 本任务只用一份材料：**你自己的 `t1.3-cmake-lib`**。实验全在本机完成，不需要下载任何东西。
> 教程只当背景读（看概念，别看路径）：<https://cmake.org/cmake/help/v3.28/guide/tutorial/index.html>

---

## 时间怎么切（2 h，全部在本机做实验）

| 时段 | 做什么 |
| --- | --- |
| 10 min | 实验 1：看清 `cmake` 和 `ninja` 各干了什么 |
| 15 min | 实验 2：把 `PUBLIC` 改成 `PRIVATE`，看 app 怎么炸 |
| 10 min | 实验 3：把内部头 include 进来，看为什么链接了也没用 |
| 15 min | 实验 4：源码目录里直接 `cmake .` 会生成什么垃圾 |
| 20 min | 实验 5：`STATIC` 改 `SHARED`，看产物和运行差别 |
| 30 min | 写这 5 题答案 |

实验前先存个档（改坏了能还原）：

```bash
cd ~/embedded-study && git add -A && git commit -m "wip: 做 T1.2 实验前" || true
```

---

## 实验 1：谁干了哪一步？

```bash
cd ~/embedded-study/w1/t1.3-cmake-lib
rm -rf build
cmake -S . -B build -G Ninja      # 只做"配置 + 生成"
ls build/                          # 出现了 build.ninja、CMakeCache.txt
cmake --build build -v             # 真正编译：看它调用的命令
```

记下：配置阶段生成了什么？`-v` 里出现的是 `ninja` 还是 `gcc`？

## 实验 2：`PUBLIC` 到底管什么？

先确保 T1.3 已经能构建（`app` 已链接 `sampstat`）。然后把 `sampstat/CMakeLists.txt` 里
`PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include` 的 **PUBLIC 改成 PRIVATE**，重新构建：

```bash
rm -rf build && cmake -S . -B build -G Ninja && cmake --build build
```

把报错原文抄进第 2 题答案，然后**改回 PUBLIC**。

## 实验 3：为什么链接了库，`internal.h` 还是看不到？

在 `app/main.c` 顶部加 `#include "internal.h"`，构建，看报错。然后删掉。

思考：库的 `PRIVATE` 包含路径，对“链接了它的可执行目标”可见吗？

## 实验 4：out-of-source 的意义

```bash
cd ~/embedded-study/w1/t1.3-cmake-lib
cmake . -G Ninja           # 故意在源码目录里配置（会生成一堆文件）
ls | head -20              # 看源码目录现在多脏
git status --short | head  # 看 git 眼里多了一堆什么
rm -f CMakeCache.txt cmake_install.cmake build.ninja rules.ninja Makefile
rm -rf CMakeFiles
```

结论写进第 4 题：为什么应该在 `build/` 里配置，而不是源码目录。

## 实验 5：静态库 vs 共享库

```bash
cd ~/embedded-study/w1/t1.3-cmake-lib
# 把 add_library(sampstat STATIC ...) 改成 SHARED，构建
ls build/app/
ldd build/app/app          # 看它依赖哪个 .so
```

记下 `.a` 与 `.so` 在“链接时”和“运行时”的差别，然后**改回 STATIC**。

---

## 第 1 题：配置、生成、构建，三步各是谁干的？

要写清：`cmake -S . -B build` 做了哪一步、`cmake --build build` 又做了哪一步、`gcc` 什么时候才真正被调用。
（证据：实验 1 的输出）

我的答案：

（这里写）

---

## 第 2 题：`PRIVATE` / `PUBLIC` / `INTERFACE` 怎么传播？

三个各举一例，说明“谁用得到”。
（证据：实验 2 的报错 + 你自己项目的 `sampstat/CMakeLists.txt`）

我的答案：

（这里写）

---

## 第 3 题：为什么用 `target_include_directories` 而不是 `include_directories`？

关键词：全局 vs 按目标、谁真正需要、依赖是否可传递。

我的答案：

（这里写）

---

## 第 4 题：源目录与构建目录分开（out-of-source）有什么好处？

（证据：实验 4 里 `git status` 看到的那些文件）

我的答案：

（这里写）

---

## 第 5 题：Zephyr 的 `find_package(Zephyr)` 和你手写的 CMakeLists 是什么关系？

去看 `~/zephyrproject/zephyr/samples/hello_world/CMakeLists.txt`（只有 6 行）。
为什么这么短就能编出一个完整固件？`find_package` 到底把什么挂进来了？

我的答案：

（这里写）

---

## 验收（我自己问自己）

- [ ] 不看笔记，能说出 `cmake` 和 `ninja` 各自负责哪一段。
- [ ] 能解释“只 include 头文件为什么还会链接失败”（T1.3 那道错就是它）。
- [ ] 能说出 `PUBLIC` 什么时候必须用、`PRIVATE` 什么时候必须用。
- [ ] 能说出 `find_package(Zephyr)` 之后，`app` 这个 target 多了什么。
