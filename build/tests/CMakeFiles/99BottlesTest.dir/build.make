# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mark/Documents/CProjects/99Bottles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mark/Documents/CProjects/99Bottles/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/99BottlesTest.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/99BottlesTest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/99BottlesTest.dir/flags.make

tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o: tests/CMakeFiles/99BottlesTest.dir/flags.make
tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o: ../tests/CapitaliserTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o -c /home/mark/Documents/CProjects/99Bottles/tests/CapitaliserTests.cpp

tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.i"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mark/Documents/CProjects/99Bottles/tests/CapitaliserTests.cpp > CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.i

tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.s"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mark/Documents/CProjects/99Bottles/tests/CapitaliserTests.cpp -o CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.s

tests/CMakeFiles/99BottlesTest.dir/tests.cpp.o: tests/CMakeFiles/99BottlesTest.dir/flags.make
tests/CMakeFiles/99BottlesTest.dir/tests.cpp.o: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/99BottlesTest.dir/tests.cpp.o"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/99BottlesTest.dir/tests.cpp.o -c /home/mark/Documents/CProjects/99Bottles/tests/tests.cpp

tests/CMakeFiles/99BottlesTest.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/99BottlesTest.dir/tests.cpp.i"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mark/Documents/CProjects/99Bottles/tests/tests.cpp > CMakeFiles/99BottlesTest.dir/tests.cpp.i

tests/CMakeFiles/99BottlesTest.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/99BottlesTest.dir/tests.cpp.s"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mark/Documents/CProjects/99Bottles/tests/tests.cpp -o CMakeFiles/99BottlesTest.dir/tests.cpp.s

tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.o: tests/CMakeFiles/99BottlesTest.dir/flags.make
tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.o: ../tests/tests_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.o"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/99BottlesTest.dir/tests_main.cpp.o -c /home/mark/Documents/CProjects/99Bottles/tests/tests_main.cpp

tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/99BottlesTest.dir/tests_main.cpp.i"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mark/Documents/CProjects/99Bottles/tests/tests_main.cpp > CMakeFiles/99BottlesTest.dir/tests_main.cpp.i

tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/99BottlesTest.dir/tests_main.cpp.s"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mark/Documents/CProjects/99Bottles/tests/tests_main.cpp -o CMakeFiles/99BottlesTest.dir/tests_main.cpp.s

# Object files for target 99BottlesTest
99BottlesTest_OBJECTS = \
"CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o" \
"CMakeFiles/99BottlesTest.dir/tests.cpp.o" \
"CMakeFiles/99BottlesTest.dir/tests_main.cpp.o"

# External object files for target 99BottlesTest
99BottlesTest_EXTERNAL_OBJECTS =

tests/99BottlesTest: tests/CMakeFiles/99BottlesTest.dir/CapitaliserTests.cpp.o
tests/99BottlesTest: tests/CMakeFiles/99BottlesTest.dir/tests.cpp.o
tests/99BottlesTest: tests/CMakeFiles/99BottlesTest.dir/tests_main.cpp.o
tests/99BottlesTest: tests/CMakeFiles/99BottlesTest.dir/build.make
tests/99BottlesTest: /usr/local/lib/libCatch2.a
tests/99BottlesTest: libSong.a
tests/99BottlesTest: libBottleNumber.a
tests/99BottlesTest: libBottleNumber0.a
tests/99BottlesTest: libBottleNumber1.a
tests/99BottlesTest: libBottleNumber6.a
tests/99BottlesTest: libBottleNumberFactory.a
tests/99BottlesTest: libCapitaliser.a
tests/99BottlesTest: libVerseFactory.a
tests/99BottlesTest: libMilkBottleVerse.a
tests/99BottlesTest: libBeerBottleVerse.a
tests/99BottlesTest: libBottleNumber.a
tests/99BottlesTest: libBottleNumber0.a
tests/99BottlesTest: libBottleNumber1.a
tests/99BottlesTest: libBottleNumber6.a
tests/99BottlesTest: tests/CMakeFiles/99BottlesTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 99BottlesTest"
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/99BottlesTest.dir/link.txt --verbose=$(VERBOSE)
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && /usr/bin/cmake -D TEST_TARGET=99BottlesTest -D TEST_EXECUTABLE=/home/mark/Documents/CProjects/99Bottles/build/tests/99BottlesTest -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/mark/Documents/CProjects/99Bottles/build/tests -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=99BottlesTest_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D CTEST_FILE=/home/mark/Documents/CProjects/99Bottles/build/tests/99BottlesTest_tests-b12d07c.cmake -P /usr/local/lib/cmake/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/99BottlesTest.dir/build: tests/99BottlesTest

.PHONY : tests/CMakeFiles/99BottlesTest.dir/build

tests/CMakeFiles/99BottlesTest.dir/clean:
	cd /home/mark/Documents/CProjects/99Bottles/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/99BottlesTest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/99BottlesTest.dir/clean

tests/CMakeFiles/99BottlesTest.dir/depend:
	cd /home/mark/Documents/CProjects/99Bottles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mark/Documents/CProjects/99Bottles /home/mark/Documents/CProjects/99Bottles/tests /home/mark/Documents/CProjects/99Bottles/build /home/mark/Documents/CProjects/99Bottles/build/tests /home/mark/Documents/CProjects/99Bottles/build/tests/CMakeFiles/99BottlesTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/99BottlesTest.dir/depend

