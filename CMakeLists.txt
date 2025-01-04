cmake_minimum_required(VERSION 3.28)

project(codeind-training LANGUAGES C)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USER_FLAG}")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${USER_LINK_FLAG}")

# ${CMAKE_LINKER_FLAGS

add_subdirectory(leetcode)
add_subdirectory(projecteuler)
add_subdirectory(test)
