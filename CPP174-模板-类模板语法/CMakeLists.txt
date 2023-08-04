cmake_minimum_required(VERSION 3.15)

#set the project name
project(AppCpp VERSION 1.0)

#add the executabal
SET(SRC_LIST main.cpp)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_executable(${PROJECT_NAME} ${SRC_LIST})

#添加mathFuncitons子目录并执行它的CMakeLists.txt
#add_subdirectory(mathFunctions)
#指定头文件包含路径
#include_directories("./mathFunctions")

#添加链接库
#target_link_libraries(${PROJECT_NAME} MathFunctions)
