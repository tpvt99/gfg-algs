# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.4746.93/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tpvt96/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.4746.93/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ActivitySelection.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ActivitySelection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ActivitySelection.dir/flags.make

CMakeFiles/ActivitySelection.dir/main.cpp.o: CMakeFiles/ActivitySelection.dir/flags.make
CMakeFiles/ActivitySelection.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ActivitySelection.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ActivitySelection.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/main.cpp

CMakeFiles/ActivitySelection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ActivitySelection.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/main.cpp > CMakeFiles/ActivitySelection.dir/main.cpp.i

CMakeFiles/ActivitySelection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ActivitySelection.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/main.cpp -o CMakeFiles/ActivitySelection.dir/main.cpp.s

# Object files for target ActivitySelection
ActivitySelection_OBJECTS = \
"CMakeFiles/ActivitySelection.dir/main.cpp.o"

# External object files for target ActivitySelection
ActivitySelection_EXTERNAL_OBJECTS =

ActivitySelection: CMakeFiles/ActivitySelection.dir/main.cpp.o
ActivitySelection: CMakeFiles/ActivitySelection.dir/build.make
ActivitySelection: CMakeFiles/ActivitySelection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ActivitySelection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ActivitySelection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ActivitySelection.dir/build: ActivitySelection
.PHONY : CMakeFiles/ActivitySelection.dir/build

CMakeFiles/ActivitySelection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ActivitySelection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ActivitySelection.dir/clean

CMakeFiles/ActivitySelection.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter20.Greedy/ActivitySelection/cmake-build-debug/CMakeFiles/ActivitySelection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ActivitySelection.dir/depend
