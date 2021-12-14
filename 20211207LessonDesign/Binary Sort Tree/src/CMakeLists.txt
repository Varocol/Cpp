# 添加包含目录
include_directories(${PATH}/lib)
# 添加附加静态lib
link_libraries(libs)
# 生成文件列表
aux_source_directory(. SRC_FILES)
# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})
# 添加动态链接库dll
# target_link_libraries(${PROJECT_NAME} libs)