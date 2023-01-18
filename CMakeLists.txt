# CMake最低版本
cmake_minimum_required(VERSION 3.0)

# 获取当前文件夹
STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

# 项目名称
project(cmake-study)

configure_file(

    ${PROJECT_SOURCE_DIR}/src/config.h.in
    
    ${PROJECT_BINARY_DIR}/src/config.h

)

message("zzzzzzzzzzzzzzzzzzzz")

option(USESUBMODULE "use submodel" ON)
if (USESUBMODULE)

    # 设置变量
    set(SUBMODULE myfunc)

    # 添加包含路径
    # include_directories(${SUBMODULE})

    # 添加子目录
    # 必须放在aux_source_directory前,否则同名变量SRCS会冲突
    add_subdirectory(${SUBMODULE})

    # 设置附加变量
    set(EXTRA_LIBS ${EXTRA_LIBS} ${SUBMODULE})
    
    message("join to set sub model config")
endif (USESUBMODULE)    


# 查找src目录下所有的源文件并保存到变量
aux_source_directory(./src/ SRCS)

include_directories(${PROJECT_BINARY_DIR}/src)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/src/config.h" DESTINATION include)
