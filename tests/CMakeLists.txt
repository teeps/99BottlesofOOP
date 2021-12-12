cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/test/cmake")

set (WILDCARD_SOURCE *.cpp)

file(GLOB_RECURSE TEST_SOURCES ${WILDCARD_SOURCE})
set(TARGET_TEST "99BottlesTest")

add_executable(${TARGET_TEST} ${TEST_SOURCES})

find_package(Catch2 REQUIRED)

# Link to the desired libraries
target_link_libraries(${TARGET_TEST}
    PRIVATE
    Catch2::Catch2
    BottleSong
    Capitaliser
)
include(CTest)
include(Catch)

#include(ParseAndAddCatchTests)
#ParseAndAddCatchTests(${TARGET_TEST})
catch_discover_tests(${TARGET_TEST})