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
CMAKE_COMMAND = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BalancedParanthesis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BalancedParanthesis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BalancedParanthesis.dir/flags.make

CMakeFiles/BalancedParanthesis.dir/main.cpp.o: CMakeFiles/BalancedParanthesis.dir/flags.make
CMakeFiles/BalancedParanthesis.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BalancedParanthesis.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BalancedParanthesis.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/main.cpp

CMakeFiles/BalancedParanthesis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BalancedParanthesis.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/main.cpp > CMakeFiles/BalancedParanthesis.dir/main.cpp.i

CMakeFiles/BalancedParanthesis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BalancedParanthesis.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/main.cpp -o CMakeFiles/BalancedParanthesis.dir/main.cpp.s

# Object files for target BalancedParanthesis
BalancedParanthesis_OBJECTS = \
"CMakeFiles/BalancedParanthesis.dir/main.cpp.o"

# External object files for target BalancedParanthesis
BalancedParanthesis_EXTERNAL_OBJECTS =

BalancedParanthesis: CMakeFiles/BalancedParanthesis.dir/main.cpp.o
BalancedParanthesis: CMakeFiles/BalancedParanthesis.dir/build.make
BalancedParanthesis: CMakeFiles/BalancedParanthesis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BalancedParanthesis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BalancedParanthesis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BalancedParanthesis.dir/build: BalancedParanthesis

.PHONY : CMakeFiles/BalancedParanthesis.dir/build

CMakeFiles/BalancedParanthesis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BalancedParanthesis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BalancedParanthesis.dir/clean

CMakeFiles/BalancedParanthesis.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/BalancedParanthesis/cmake-build-debug/CMakeFiles/BalancedParanthesis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BalancedParanthesis.dir/depend

