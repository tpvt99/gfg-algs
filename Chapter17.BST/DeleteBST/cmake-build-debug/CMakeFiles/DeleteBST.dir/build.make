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
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DeleteBST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DeleteBST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DeleteBST.dir/flags.make

CMakeFiles/DeleteBST.dir/main.cpp.o: CMakeFiles/DeleteBST.dir/flags.make
CMakeFiles/DeleteBST.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DeleteBST.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DeleteBST.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/main.cpp

CMakeFiles/DeleteBST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeleteBST.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/main.cpp > CMakeFiles/DeleteBST.dir/main.cpp.i

CMakeFiles/DeleteBST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeleteBST.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/main.cpp -o CMakeFiles/DeleteBST.dir/main.cpp.s

# Object files for target DeleteBST
DeleteBST_OBJECTS = \
"CMakeFiles/DeleteBST.dir/main.cpp.o"

# External object files for target DeleteBST
DeleteBST_EXTERNAL_OBJECTS =

DeleteBST: CMakeFiles/DeleteBST.dir/main.cpp.o
DeleteBST: CMakeFiles/DeleteBST.dir/build.make
DeleteBST: CMakeFiles/DeleteBST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DeleteBST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeleteBST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DeleteBST.dir/build: DeleteBST

.PHONY : CMakeFiles/DeleteBST.dir/build

CMakeFiles/DeleteBST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DeleteBST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DeleteBST.dir/clean

CMakeFiles/DeleteBST.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter17.BST/DeleteBST/cmake-build-debug/CMakeFiles/DeleteBST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DeleteBST.dir/depend

