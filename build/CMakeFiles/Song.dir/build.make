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
include CMakeFiles/Song.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Song.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Song.dir/flags.make

CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o: CMakeFiles/Song.dir/flags.make
CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o: ../src/BottleSong/Song.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o -c /home/mark/Documents/CProjects/99Bottles/src/BottleSong/Song.cpp

CMakeFiles/Song.dir/src/BottleSong/Song.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Song.dir/src/BottleSong/Song.cpp.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mark/Documents/CProjects/99Bottles/src/BottleSong/Song.cpp > CMakeFiles/Song.dir/src/BottleSong/Song.cpp.i

CMakeFiles/Song.dir/src/BottleSong/Song.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Song.dir/src/BottleSong/Song.cpp.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mark/Documents/CProjects/99Bottles/src/BottleSong/Song.cpp -o CMakeFiles/Song.dir/src/BottleSong/Song.cpp.s

# Object files for target Song
Song_OBJECTS = \
"CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o"

# External object files for target Song
Song_EXTERNAL_OBJECTS =

libSong.a: CMakeFiles/Song.dir/src/BottleSong/Song.cpp.o
libSong.a: CMakeFiles/Song.dir/build.make
libSong.a: CMakeFiles/Song.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mark/Documents/CProjects/99Bottles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSong.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Song.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Song.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Song.dir/build: libSong.a

.PHONY : CMakeFiles/Song.dir/build

CMakeFiles/Song.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Song.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Song.dir/clean

CMakeFiles/Song.dir/depend:
	cd /home/mark/Documents/CProjects/99Bottles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mark/Documents/CProjects/99Bottles /home/mark/Documents/CProjects/99Bottles /home/mark/Documents/CProjects/99Bottles/build /home/mark/Documents/CProjects/99Bottles/build /home/mark/Documents/CProjects/99Bottles/build/CMakeFiles/Song.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Song.dir/depend

