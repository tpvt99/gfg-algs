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
CMAKE_COMMAND = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GetMinStack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GetMinStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GetMinStack.dir/flags.make

CMakeFiles/GetMinStack.dir/main.cpp.o: CMakeFiles/GetMinStack.dir/flags.make
CMakeFiles/GetMinStack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GetMinStack.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GetMinStack.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/main.cpp

CMakeFiles/GetMinStack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GetMinStack.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/main.cpp > CMakeFiles/GetMinStack.dir/main.cpp.i

CMakeFiles/GetMinStack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GetMinStack.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/main.cpp -o CMakeFiles/GetMinStack.dir/main.cpp.s

# Object files for target GetMinStack
GetMinStack_OBJECTS = \
"CMakeFiles/GetMinStack.dir/main.cpp.o"

# External object files for target GetMinStack
GetMinStack_EXTERNAL_OBJECTS =

GetMinStack: CMakeFiles/GetMinStack.dir/main.cpp.o
GetMinStack: CMakeFiles/GetMinStack.dir/build.make
GetMinStack: CMakeFiles/GetMinStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GetMinStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetMinStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GetMinStack.dir/build: GetMinStack

.PHONY : CMakeFiles/GetMinStack.dir/build

CMakeFiles/GetMinStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GetMinStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GetMinStack.dir/clean

CMakeFiles/GetMinStack.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/GetMinStack/cmake-build-debug/CMakeFiles/GetMinStack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GetMinStack.dir/depend
