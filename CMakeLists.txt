cmake_minimum_required(VERSION 3.13)

#Project Name
project(99Bottles VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(TARGET_NAME "99Bottles")

#Set project source directory
set(PROJECT_SOURCE_DIR 
        "src")

set(PROJECT_BINARY_DIR
        "${CMAKE_CURRENT_SOURCE_DIR}/build")

#Modules
add_library (BottleNumber "${PROJECT_SOURCE_DIR}/BottleSong/BottleNumber.cpp")
add_library (BottleNumber0 "${PROJECT_SOURCE_DIR}/BottleSong/BottleNumber0.cpp")
add_library (BottleNumber1 "${PROJECT_SOURCE_DIR}/BottleSong/BottleNumber1.cpp")
add_library (BottleNumber6 "${PROJECT_SOURCE_DIR}/BottleSong/BottleNumber6.cpp")
add_library (BottleNumberFactory "${PROJECT_SOURCE_DIR}/BottleSong/BottleNumberFactory.cpp")
add_library (BottleSong "${PROJECT_SOURCE_DIR}/BottleSong/BottleSong.cpp")
add_library (Capitaliser "${PROJECT_SOURCE_DIR}/Capitaliser/Capitaliser.cpp")
#add the executable
add_executable(99Bottles ${PROJECT_SOURCE_DIR}/99bottles.cpp)
target_link_libraries(99Bottles BottleSong BottleNumber BottleNumber0 BottleNumber1 
    BottleNumber6
    BottleNumberFactory)

#include directories
target_include_directories(${TARGET_NAME} PUBLIC 
                            "${PROJECT_SOURCE_DIR}")

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



