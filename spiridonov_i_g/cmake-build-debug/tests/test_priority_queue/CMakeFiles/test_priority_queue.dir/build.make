# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/rtviwe/clion-2018.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rtviwe/clion-2018.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rtviwe/CLionProjects/misis/spiridonov_i_g

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug

# Include any dependencies generated for this target.
include tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/depend.make

# Include the progress variables for this target.
include tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/progress.make

# Include the compile flags for this target's objects.
include tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/flags.make

tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.o: tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/flags.make
tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.o: ../tests/test_priority_queue/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.o"
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_priority_queue.dir/main.cpp.o -c /home/rtviwe/CLionProjects/misis/spiridonov_i_g/tests/test_priority_queue/main.cpp

tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_priority_queue.dir/main.cpp.i"
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rtviwe/CLionProjects/misis/spiridonov_i_g/tests/test_priority_queue/main.cpp > CMakeFiles/test_priority_queue.dir/main.cpp.i

tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_priority_queue.dir/main.cpp.s"
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rtviwe/CLionProjects/misis/spiridonov_i_g/tests/test_priority_queue/main.cpp -o CMakeFiles/test_priority_queue.dir/main.cpp.s

# Object files for target test_priority_queue
test_priority_queue_OBJECTS = \
"CMakeFiles/test_priority_queue.dir/main.cpp.o"

# External object files for target test_priority_queue
test_priority_queue_EXTERNAL_OBJECTS =

tests/test_priority_queue/test_priority_queue: tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/main.cpp.o
tests/test_priority_queue/test_priority_queue: tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/build.make
tests/test_priority_queue/test_priority_queue: labs/priority_queue/libpriority_queue.a
tests/test_priority_queue/test_priority_queue: tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_priority_queue"
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_priority_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/build: tests/test_priority_queue/test_priority_queue

.PHONY : tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/build

tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/clean:
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue && $(CMAKE_COMMAND) -P CMakeFiles/test_priority_queue.dir/cmake_clean.cmake
.PHONY : tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/clean

tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/depend:
	cd /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rtviwe/CLionProjects/misis/spiridonov_i_g /home/rtviwe/CLionProjects/misis/spiridonov_i_g/tests/test_priority_queue /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue /home/rtviwe/CLionProjects/misis/spiridonov_i_g/cmake-build-debug/tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/test_priority_queue/CMakeFiles/test_priority_queue.dir/depend

