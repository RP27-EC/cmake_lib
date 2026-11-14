cmake_minimum_required(VERSION 3.15)
project(test)
#定义变量
#静态库的路径
set(LIBPATH ${PROJECT_BINARY_DIR}/lib)
#可执行文件的路径
set(EXECPATH ${PROJECT_BINARY_DIR}/bin)
#头文件的路径
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)
#库文件的名字
set(CALCLIB calc)
set(SORTLIB sort)
#可执行文件的名字
set(APPNAME1 app1)
set(APPNAME2 app2)

#添加子目录
add_subdirectory(calc)
add_subdirectory(sort)
add_subdirectory(test1)
add_subdirectory(test2)
