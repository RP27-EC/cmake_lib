add_library(sampstat STATIC
    src/sampstat.c
)

# 公开头目录：链接本库的人自动获得 include/sampstat 路径
target_include_directories(sampstat
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(sampstat PRIVATE -Wall -Wextra)
