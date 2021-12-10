cmake_minimum_required(VERSION 3.13)

#Project Name
project(99Bottles VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(TARGET_NAME "99Bottles")
#googletest inclusion
#include(FetchContent)
#FetchContent_Declare(
#    googletest
#    #specify the location, and if you like the desired commit.
#    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
#)
#FetchContent_MakeAvailable(googletest)

#Set project source directory
set(PROJECT_SOURCE_DIR 
        "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(PROJECT_BINARY_DIR
        "${CMAKE_CURRENT_SOURCE_DIR}/build")

#Modules
add_library (BottleSong ${PROJECT_SOURCE_DIR}/BottleSong.cpp)
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../Catch2")
#add the executable

add_executable(${TARGET_NAME} ${PROJECT_SOURCE_DIR}/99bottles.cpp)

#include directories
target_include_directories(${TARGET_NAME} PUBLIC 
                            "${CMAKE_CURRENT_SOURCE_DIR}/src")
#Configure a header file to pass the version number to the source code:
configure_file(99BottlesConfig.h.in 99BottlesConfig.h)

include(CTest)

target_compile_definitions(${TARGET_NAME} PRIVATE
    TEST_DATA_PATH="${PROJECT_SOURCE_DIR}/data")

#set environment variable to ON if you want to enable testing
#if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
#endif()



