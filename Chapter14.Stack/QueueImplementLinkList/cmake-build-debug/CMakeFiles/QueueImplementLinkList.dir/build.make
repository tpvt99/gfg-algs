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
CMAKE_SOURCE_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QueueImplementLinkList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QueueImplementLinkList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QueueImplementLinkList.dir/flags.make

CMakeFiles/QueueImplementLinkList.dir/main.cpp.o: CMakeFiles/QueueImplementLinkList.dir/flags.make
CMakeFiles/QueueImplementLinkList.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QueueImplementLinkList.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QueueImplementLinkList.dir/main.cpp.o -c /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/main.cpp

CMakeFiles/QueueImplementLinkList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QueueImplementLinkList.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/main.cpp > CMakeFiles/QueueImplementLinkList.dir/main.cpp.i

CMakeFiles/QueueImplementLinkList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QueueImplementLinkList.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/main.cpp -o CMakeFiles/QueueImplementLinkList.dir/main.cpp.s

# Object files for target QueueImplementLinkList
QueueImplementLinkList_OBJECTS = \
"CMakeFiles/QueueImplementLinkList.dir/main.cpp.o"

# External object files for target QueueImplementLinkList
QueueImplementLinkList_EXTERNAL_OBJECTS =

QueueImplementLinkList: CMakeFiles/QueueImplementLinkList.dir/main.cpp.o
QueueImplementLinkList: CMakeFiles/QueueImplementLinkList.dir/build.make
QueueImplementLinkList: CMakeFiles/QueueImplementLinkList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable QueueImplementLinkList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QueueImplementLinkList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QueueImplementLinkList.dir/build: QueueImplementLinkList

.PHONY : CMakeFiles/QueueImplementLinkList.dir/build

CMakeFiles/QueueImplementLinkList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QueueImplementLinkList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QueueImplementLinkList.dir/clean

CMakeFiles/QueueImplementLinkList.dir/depend:
	cd /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug /home/tpvt96/cs_course/gfg-algs/Chapter14.Stack/QueueImplementLinkList/cmake-build-debug/CMakeFiles/QueueImplementLinkList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QueueImplementLinkList.dir/depend
