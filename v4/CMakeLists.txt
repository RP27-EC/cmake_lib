# 指定cmake版本
cmake_minimum_required(VERSION 3.10)
# 指定项目名称
project(hello)
#SET(SRC_LIST add.cpp div.cpp mult.cpp main.cpp sub.cpp)
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
#这个project_source_dir就是当前CMakeLists.txt所在的路径，SRC就是变量名，SRC里面存放的是当前目录下所有的源文件
#file (GLOB SRC_LIST *.cpp)
file (GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
#CMAKE_CURRENT_SOURCE_DIR就是当前CMakeLists.txt所在的路径,和上面的PROJECT_SOURCE_DIR是一样的，SRC_LIST就是变量名，SRC_LIST里面存放的是当前目录下所有的源文件
#set(EXECUTABLE_OUTPUT_PATH /home/hqz/embedded-study/v1/build/aa/bb)
include_directories(${PROJECT_SOURCE_DIR}/include)
#add_library(calc SHARED ${SRC_LIST})
#add_library(calc STATIC ${SRC_LIST})
#set(CMAKE_CXX_STANDARD 11)
#link_libraries(calc)
#link_directories(${PROJECT_SOURCE_DIR}/lib1)
#这个是自定义的库文件，所以需要指定路径，calc是库文件的名称，libcalc.a就是静态库文件的名称
message("xxxxxxx")
add_executable(test ${SRC_LIST})  
target_link_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/lib2)
message(STATUS "11111111")
target_link_libraries(test PRIVATE calc)
#message(FATAL_ERROR "22222")
#执行完这个后就会停止执行，后面的代码不会被执行
message(STATUS "3333333")
# 指定生成目标
#add_executable()
# 可执行文件的名称   源文件名称

#例1  可以空格也可以分号
#add_executable(APP add.c)
# 例2
# add_executable(app;add.c)

# cmake需要在当前目录去cmake命令，或者跳转到指定目录去执行cmake命令

# cmake的执行流程
#对应文件夹终端执行cmake
#然后make
#ls看是否有生成可执行文件
#./可执行文件名称即可

 # cmake生成的临时文件有点多，可以放到指定的文件夹中
 # 然后在指定的文件夹中执行cmake命令，需要指定源文件的路径
 #这样子临时文件就会生成在指定的文件夹中
 #例子
 #mkdir build
    #cd build
    #cmake ..
    #make


#set的使用
#在上面中5个源文件如果不想一个一个的写，可以使用set命令
#set(SRC_LIST add.cpp div.cpp mult.cpp main.cpp sub.cpp)
# 相当于把他们放在一个变量中，SRC_LIST就是变量名，更加方便管理
#若要使用
#add_executable(test ${SRC_LIST})   ${SRC_LIST}就是变量的使用方式 里面写的就是变量名

# 指定C++标准
# set(CMAKE_CXX_STANDARD 11) 
#这种是写在CMakeLists.txt中，指定C++标准为C++11
#还可以写在命令行中，cmake -DCMAKE_CXX_STANDARD=11 .. 这样子指定C++标准为C++11

# 指定输出的路径
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#一般我们都使用绝对路径，${PROJECT_SOURCE_DIR}就是当前CMakeLists.txt所在的路径

# 搜索文件
# 方法1
# aux_source_directory( <dir> <variable> )
# 例子
# aux_source_directory(. DIR_SRCS)
# dir是要搜索的目录，variable是变量名，DIR_SRCS就是变量名
# 方法2
# file(GLOB <variable> <globbing expressions>...)
# file (GLOB/GLOB_RECURSE   变量名  要搜索的文件路径和文件类型)
#GLOB:将在指定目录下搜索符合条件的文件，GLOB_RECURSE:将在指定目录及其子目录下搜索符合条件的文件（递归搜索）
# 例子
# file(GLOB DIR_SRCS *.cpp)
# GLOB，*.cpp就是搜索当前目录下所有的cpp文件，DIR_SRCS就是变量名

# cd 进入某个文件夹
# cd ..            cd v1/   cd build/等等
# rm * -rf
#mkdir    mv等   cmake ..

#指定头文件的路径
# include_directories(${PROJECT_SOURCE_DIR}/include)

#制作库文件的话比如动态库文件等目前这个main不需要，它只是一个测试程序

# 制作静态库 add_library(库名称 STATIC 源文件列表（源文件1  源文件2  源文件3 ）)
#在linux中，静态库文件的后缀名是.a，动态库文件的后缀名是.so
#lib+库名称+.a就是静态库文件的名称
#动态库文件的名称是lib+库名称+.so
#add_library(库名称 SHARED 源文件列表（源文件1  源文件2  源文件3 ）)

# 动态库是有可执行权限的，静态库是没有可执行权限的，静态库是被链接到可执行文件中去的，动态库是被加载到内存中去的

#链接静态库
#link_libraries(<static lib>  [<static lib> ...])
#<static lib>是静态库的名称，多个静态库之间用空格隔开  可以是全名lib+库名称+.a 也可以是库名称
#库文件是系统的话，可以不用指定路径，库文件是自己制作的静态库的话，需要指定路径
#就对应：link_directories(<dir> [<dir> ...])  <dir>是库文件所在的路径，多个路径之间用空格隔开

#所以总结下实现了什么功能，就是在生成可执行文件的时候，链接了一个静态库文件，这个静态库文件是自己制作的，所以需要指定路径，链接的静态库文件是calc.a 这个静态库文件里面有一些函数，这些函数在test.cpp中被调用了，所以在生成可执行文件的时候，需要链接这个静态库文件
#然后我们学的就是如何把这个库文件给添加进cmakelist

#链接多个动态库文件
#target_link_libraries(<target>  <PRIVATE|PUBLIC|INTERFACE>  <lib> [<lib> ...])
#target 动态库文件名字，可能是源文件，动态库文件，可执行文件等
#PRIVATE|PUBLIC|INTERFACE 这三个是链接的方式，PRIVATE是私有的，PUBLIC是公有的，INTERFACE是接口的意思
#默认是PRIVATE，PRIVATE是私有的，只有当前目标可以使用这个库文件，PUBLIC是公有的，当前目标和依赖当前目标的目标都可以使用这个库文件，INTERFACE是接口的意思，只有依赖当前目标的目标可以使用这个库文件

#这个target_link_libraries一般放在生成可执行文件的后面即可

#只有可执行程序用到动态库的时候，这部分内容才会被加载到内存中去，静态库是被链接到可执行文件中去的，所以静态库是没有可执行权限的，动态库是有可执行权限的

#日志
#message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}") 
#无  代表重要信息
#STATUS  非重要信息
#WARNING  警告信息 会继续执行
#AUTHOR_WARNING  警告信息 会继续执行
#SEND_ERROR  错误信息 会继续执行
#FATAL_ERROR  致命错误信息 会停止执行

#字符串
#set(变量名 "字符串")  变量名就是变量的名称，字符串就是变量的值

#使用list拼接字符串
#list(APPEND <list> <element>...)  追加(拼接)

#[[
cmake_minimum_required(VERSION 3.0)
project(TEST)
set(TEMP "hello,world")
file(GLOB SRC_1 ${PROJECT_SOURCE_DIR}/src1/*.cpp)
file(GLOB SRC_2 ${PROJECT_SOURCE_DIR}/src2/*.cpp)
# 追加(拼接)
set(SRC_1 ${SRC_1} ${SRC_2} ${TEMP})
message(STATUS "message: ${SRC_1}")
]]

#字符串的移除
#list(REMOVE_ITEM <list> <element>...)
#例子
#list(REMOVE_ITEM SRC_1 ${TEMP})

