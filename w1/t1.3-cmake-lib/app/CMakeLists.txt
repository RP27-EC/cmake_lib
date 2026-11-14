add_executable(app main.c)

# TODO(T1.2)：让 app 通过"链接库"拿到 sampstat 的实现和公开头文件路径。
# 补下面这一行（把问号换掉），不要在这里写 include_directories：
# target_link_libraries(app PRIVATE ???)

target_link_libraries(app PRIVATE sampstat)