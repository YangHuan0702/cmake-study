# CMake最低版本
cmake_minimum_required(VERSION 3.0)

# 获取当前文件夹
STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

# 项目名称
project(cmake-study)

# 设置变量
set(SUBMODULE myfunc)

# 添加子目录
# 必须放在aux_source_directory前,否则同名变量SRCS会冲突
add_subdirectory(${SUBMODULE})

# 查找src目录下所有的源文件并保存到变量
aux_source_directory(./src/ SRCS)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SUBMODULE})
