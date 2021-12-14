# 搜索文件
aux_source_directory(. LIB_FILES)
# 生成链接库
add_library(libs ${LIB_FILES})