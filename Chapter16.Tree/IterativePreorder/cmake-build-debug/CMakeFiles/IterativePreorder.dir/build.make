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
CMAKE_COMMAND = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IterativePreorder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IterativePreorder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IterativePreorder.dir/flags.make

CMakeFiles/IterativePreorder.dir/main.cpp.o: CMakeFiles/IterativePreorder.dir/flags.make
CMakeFiles/IterativePreorder.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IterativePreorder.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IterativePreorder.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/main.cpp

CMakeFiles/IterativePreorder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IterativePreorder.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/main.cpp > CMakeFiles/IterativePreorder.dir/main.cpp.i

CMakeFiles/IterativePreorder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IterativePreorder.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/main.cpp -o CMakeFiles/IterativePreorder.dir/main.cpp.s

# Object files for target IterativePreorder
IterativePreorder_OBJECTS = \
"CMakeFiles/IterativePreorder.dir/main.cpp.o"

# External object files for target IterativePreorder
IterativePreorder_EXTERNAL_OBJECTS =

IterativePreorder: CMakeFiles/IterativePreorder.dir/main.cpp.o
IterativePreorder: CMakeFiles/IterativePreorder.dir/build.make
IterativePreorder: CMakeFiles/IterativePreorder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IterativePreorder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IterativePreorder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IterativePreorder.dir/build: IterativePreorder

.PHONY : CMakeFiles/IterativePreorder.dir/build

CMakeFiles/IterativePreorder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IterativePreorder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IterativePreorder.dir/clean

CMakeFiles/IterativePreorder.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter16.Tree/IterativePreorder/cmake-build-debug/CMakeFiles/IterativePreorder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IterativePreorder.dir/depend

