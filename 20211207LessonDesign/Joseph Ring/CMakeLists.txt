cmake_minimum_required(VERSION 3.0.0)
project(Joseph_Ring VERSION 0.1.0)

#设置根目录路径
set(PATH ${PROJECT_SOURCE_DIR})

# 添加lib子目录
add_subdirectory(lib)
# 添加src子目录
add_subdirectory(src)

# add_executable(${PROJECT_NAME} )
# target_link_libraries(${PROJECT_NAME} ${libs})
