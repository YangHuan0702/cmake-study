cmake_minimum_required(VERSION 3.0)
# 获取当前文件名
STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

project(${CURRENT_FOLDER})

aux_source_directory(. SRCS)

add_library(${CURRENT_FOLDER} SHARED ${SRCS})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME}.h DESTINATION include)