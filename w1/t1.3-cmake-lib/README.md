# T1.3 CMake 小库：sampstat

对应队内要求「会写基本 CMakeLists，编一个小库」。

## 题目

输入一串 `int16_t` 采样，输出：最小值、最大值、平均值、方差（总体方差，除以 n）。

## 目录

```
t1.3-cmake-lib/
├── CMakeLists.txt                       # 顶层：add_subdirectory
├── sampstat/
│   ├── CMakeLists.txt                   # 库目标（已写好）
│   ├── include/sampstat/sampstat.h      # 公开头
│   └── src/{sampstat.c, internal.h}     # 实现 + 内部头（不外泄）
└── app/
    ├── CMakeLists.txt                   # 可执行目标（缺一行 TODO）
    └── main.c                           # 已写好，负责解析参数并打印
```

## 你要做的 4 件事

1. `app/CMakeLists.txt` 里补那行 `target_link_libraries(app PRIVATE ???)`。
2. `sampstat.c` 的 TODO 1：参数校验（NULL / n==0），返回值约定写进本文件。
3. TODO 2：解释为什么求和要用 `int64_t`（提示：`32767 * 256` 已经超 `int16_t`）。
4. TODO 3：算 min/max/mean/var。

## 怎么跑

```bash
cd ~/embedded-study/w1/t1.3-cmake-lib
cmake -S . -B build -G Ninja
cmake --build build
./build/app/app 1 2 3
./build/app/app 100 200 300 400
```

**期望输出**（用来对答案）：

```text
n=3 min=1 max=3 mean=2.000 var=0.667
n=4 min=100 max=400 mean=250.000 var=12500.000
```

## 验收标准（勾完再进 T1.4）

- [ ] `cmake -S . -B build -G Ninja && cmake --build build` 一次通过，**无警告**。
- [ ] `app/CMakeLists.txt` 里没有任何 include 路径，只靠链接 `sampstat` 拿到头文件。
- [ ] 在 `main.c` 里 `#include "internal.h"` 会编译失败——把失败信息贴进本文件。
- [ ] 空数组（不带参数）、NULL 指针、极值 `32767` 都不崩，行为明确。
- [ ] 加第二个可执行目标 `app2`（只打印平均值），**不改 `sampstat/CMakeLists.txt`** 就能构建。
- [ ] 把 `add_library` 的 `STATIC` 改成 `SHARED` 再构建一次，说明 `.so` 与 `.a` 在链接和运行时的区别。

## 我的返回值约定

（写完自己填：NULL 返回 X，n==0 返回 Y）

## 我踩的坑

（自己填）
