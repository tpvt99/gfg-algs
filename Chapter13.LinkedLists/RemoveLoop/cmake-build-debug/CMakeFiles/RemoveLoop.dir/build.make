# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RemoveLoop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RemoveLoop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RemoveLoop.dir/flags.make

CMakeFiles/RemoveLoop.dir/main.cpp.o: CMakeFiles/RemoveLoop.dir/flags.make
CMakeFiles/RemoveLoop.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RemoveLoop.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoveLoop.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/main.cpp

CMakeFiles/RemoveLoop.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoveLoop.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/main.cpp > CMakeFiles/RemoveLoop.dir/main.cpp.i

CMakeFiles/RemoveLoop.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoveLoop.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/main.cpp -o CMakeFiles/RemoveLoop.dir/main.cpp.s

# Object files for target RemoveLoop
RemoveLoop_OBJECTS = \
"CMakeFiles/RemoveLoop.dir/main.cpp.o"

# External object files for target RemoveLoop
RemoveLoop_EXTERNAL_OBJECTS =

RemoveLoop: CMakeFiles/RemoveLoop.dir/main.cpp.o
RemoveLoop: CMakeFiles/RemoveLoop.dir/build.make
RemoveLoop: CMakeFiles/RemoveLoop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RemoveLoop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemoveLoop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RemoveLoop.dir/build: RemoveLoop

.PHONY : CMakeFiles/RemoveLoop.dir/build

CMakeFiles/RemoveLoop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RemoveLoop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RemoveLoop.dir/clean

CMakeFiles/RemoveLoop.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/RemoveLoop/cmake-build-debug/CMakeFiles/RemoveLoop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RemoveLoop.dir/depend
