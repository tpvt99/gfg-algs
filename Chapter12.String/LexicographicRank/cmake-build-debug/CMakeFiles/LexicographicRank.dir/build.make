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
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LexicographicRank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LexicographicRank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LexicographicRank.dir/flags.make

CMakeFiles/LexicographicRank.dir/main.cpp.o: CMakeFiles/LexicographicRank.dir/flags.make
CMakeFiles/LexicographicRank.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LexicographicRank.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LexicographicRank.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/main.cpp

CMakeFiles/LexicographicRank.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LexicographicRank.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/main.cpp > CMakeFiles/LexicographicRank.dir/main.cpp.i

CMakeFiles/LexicographicRank.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LexicographicRank.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/main.cpp -o CMakeFiles/LexicographicRank.dir/main.cpp.s

# Object files for target LexicographicRank
LexicographicRank_OBJECTS = \
"CMakeFiles/LexicographicRank.dir/main.cpp.o"

# External object files for target LexicographicRank
LexicographicRank_EXTERNAL_OBJECTS =

LexicographicRank: CMakeFiles/LexicographicRank.dir/main.cpp.o
LexicographicRank: CMakeFiles/LexicographicRank.dir/build.make
LexicographicRank: CMakeFiles/LexicographicRank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LexicographicRank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LexicographicRank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LexicographicRank.dir/build: LexicographicRank

.PHONY : CMakeFiles/LexicographicRank.dir/build

CMakeFiles/LexicographicRank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LexicographicRank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LexicographicRank.dir/clean

CMakeFiles/LexicographicRank.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter12.String/LexicographicRank/cmake-build-debug/CMakeFiles/LexicographicRank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LexicographicRank.dir/depend

