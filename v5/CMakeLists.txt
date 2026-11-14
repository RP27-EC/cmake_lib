# 指定cmake版本
cmake_minimum_required(VERSION 3.10)
# 指定项目名称
project(hello)
#SET(SRC_LIST add.cpp div.cpp mult.cpp main.cpp sub.cpp)
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
#这个project_source_dir就是当前CMakeLists.txt所在的路径，SRC就是变量名，SRC里面存放的是当前目录下所有的源文件
#file (GLOB SRC_LIST *.cpp)
file (GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
#CMAKE_CURRENT_SOURCE_DIR就是当前CMakeLists.txt所在的路径,和上面的PROJECT_SOURCE_DIR是一样的，SRC_LIST就是变量名，SRC_LIST里面存放的是当前目录下所有的源文件
#set(EXECUTABLE_OUTPUT_PATH /home/hqz/embedded-study/v1/build/aa/bb)
message("-----------")
message(${SRC_LIST})

list(REMOVE_ITEM SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

message("-----------")
message(${SRC_LIST})

include_directories(${PROJECT_SOURCE_DIR}/include)
#add_library(calc SHARED ${SRC_LIST})
add_library(calc STATIC ${SRC_LIST})

set(tmp hello world)
set(tmp1 ${tmp} ${SRC_LIST})
message(${tmp})
message(${tmp1})


list(APPEND tmp "xxxx1" "2222" ${SRC_LIST})
message(${tmp})

#set(CMAKE_CXX_STANDARD 11)
#add_executable(test ${SRC_LIST})  
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

#宏定义
#宏定义可以控制代码是否生效
#add_definitions(-DDEBUG)  #宏定义DEBUG