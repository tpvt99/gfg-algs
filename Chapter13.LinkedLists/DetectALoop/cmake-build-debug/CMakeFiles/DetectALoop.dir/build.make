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
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DetectALoop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DetectALoop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DetectALoop.dir/flags.make

CMakeFiles/DetectALoop.dir/main.cpp.o: CMakeFiles/DetectALoop.dir/flags.make
CMakeFiles/DetectALoop.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DetectALoop.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DetectALoop.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/main.cpp

CMakeFiles/DetectALoop.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DetectALoop.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/main.cpp > CMakeFiles/DetectALoop.dir/main.cpp.i

CMakeFiles/DetectALoop.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DetectALoop.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/main.cpp -o CMakeFiles/DetectALoop.dir/main.cpp.s

# Object files for target DetectALoop
DetectALoop_OBJECTS = \
"CMakeFiles/DetectALoop.dir/main.cpp.o"

# External object files for target DetectALoop
DetectALoop_EXTERNAL_OBJECTS =

DetectALoop: CMakeFiles/DetectALoop.dir/main.cpp.o
DetectALoop: CMakeFiles/DetectALoop.dir/build.make
DetectALoop: CMakeFiles/DetectALoop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DetectALoop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DetectALoop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DetectALoop.dir/build: DetectALoop

.PHONY : CMakeFiles/DetectALoop.dir/build

CMakeFiles/DetectALoop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DetectALoop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DetectALoop.dir/clean

CMakeFiles/DetectALoop.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter13.LinkedLists/DetectALoop/cmake-build-debug/CMakeFiles/DetectALoop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DetectALoop.dir/depend

