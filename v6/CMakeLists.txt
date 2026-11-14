# 指定cmake版本
cmake_minimum_required(VERSION 3.10)
# 指定项目名称
project(hello)

# 宏定义
# test.cpp 里用 #ifdef DEBUG 判断，代码里没有 #define DEBUG
# 所以要由 CMake 在编译时把 DEBUG 这个宏传进去
# add_definitions(-D宏名称)  相当于 gcc 的 -D 参数，也就是 gcc test.cpp -DDEBUG
add_definitions(-DDEBUG)  #宏定义DEBUG
#add_definitions(-DDEBUG)
# 也可以给宏赋值，比如 add_definitions(-DTIMES=5)
# 注意不要写 -DNUMBER=5：test.cpp 里已经 #define NUMBER 3，会报 "NUMBER" redefined，结果还是 3
# 不想要 DEBUG 时，把上面那行注释掉，重新 make 即可

add_executable(app test.cpp)

# 更推荐的写法：只给指定的目标定义宏，写在 add_executable 后面，-D 可以不写
# target_compile_definitions(app PRIVATE DEBUG)
