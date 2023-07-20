cmake_minimum_required(VERSION 3.23)

project(UartLog VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

set(boost_VERSION "1.81")
#set(boost_VERSION "1.75")

set(BOOST_ROOT "D:/inuWork/autoWork/boost/boost_1_81_0") # 指定Boost库的根目录
#set(BOOST_INCLUDEDIR "D:/inuWork/autoWork/boost/boost_1_81_0")
#set(BOOST_LIBRARYDIR "D:/inuWork/autoWork/boost/boost_1_81_0/stage/lib")


#set(BOOST_ROOT "D:/inuWork/autoWork/boost/boost_1_75_0") # 指定Boost库的根目录
#set(BOOST_INCLUDEDIR "D:/inuWork/autoWork/boost/boost_1_75_0")
#set(BOOST_LIBRARYDIR "D:/inuWork/autoWork/boost/boost_1_75_0/x64/lib")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_ARCHITECTURE "-x64")    # 指定库架构为x64
#set(Boost_ARCHITECTURE "-gd-x64")    # 指定库架构为x64
#find_package(Boost COMPONENTS atomic REQUIRED)    # 查找Boost库

message("boost Version: " "${boost_VERSION}")

set(Boost_Required_Libs system filesystem thread)

find_package(Boost ${boost_VERSION} EXACT REQUIRED ${Boost_Required_Libs})  # 查找Boost库

include_directories(${Boost_INCLUDE_DIRS})    # 包含Boost库的头文件目录

MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")

add_executable(${PROJECT_NAME} CUartLog.cpp main.cpp getopt.c)


target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS}) 
target_link_directories(${PROJECT_NAME} PUBLIC ${Boost_LIBRARY_DIR})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})    # 链接Boost库
