cmake_minimum_required(VERSION 3.20)
project(sampstat_demo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(sampstat)
add_subdirectory(app)
