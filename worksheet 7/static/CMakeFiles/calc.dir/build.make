# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aakash/4333520/Worksheet4/calc_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aakash/4333520/Worksheet4/calc_cmake/static

# Include any dependencies generated for this target.
include CMakeFiles/calc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc.dir/flags.make

CMakeFiles/calc.dir/calc.cpp.o: CMakeFiles/calc.dir/flags.make
CMakeFiles/calc.dir/calc.cpp.o: ../calc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aakash/4333520/Worksheet4/calc_cmake/static/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calc.dir/calc.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calc.dir/calc.cpp.o -c /Users/aakash/4333520/Worksheet4/calc_cmake/calc.cpp

CMakeFiles/calc.dir/calc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calc.dir/calc.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aakash/4333520/Worksheet4/calc_cmake/calc.cpp > CMakeFiles/calc.dir/calc.cpp.i

CMakeFiles/calc.dir/calc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calc.dir/calc.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aakash/4333520/Worksheet4/calc_cmake/calc.cpp -o CMakeFiles/calc.dir/calc.cpp.s

# Object files for target calc
calc_OBJECTS = \
"CMakeFiles/calc.dir/calc.cpp.o"

# External object files for target calc
calc_EXTERNAL_OBJECTS =

calc: CMakeFiles/calc.dir/calc.cpp.o
calc: CMakeFiles/calc.dir/build.make
calc: libmaths.a
calc: CMakeFiles/calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aakash/4333520/Worksheet4/calc_cmake/static/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc.dir/build: calc

.PHONY : CMakeFiles/calc.dir/build

CMakeFiles/calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calc.dir/clean

CMakeFiles/calc.dir/depend:
	cd /Users/aakash/4333520/Worksheet4/calc_cmake/static && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aakash/4333520/Worksheet4/calc_cmake /Users/aakash/4333520/Worksheet4/calc_cmake /Users/aakash/4333520/Worksheet4/calc_cmake/static /Users/aakash/4333520/Worksheet4/calc_cmake/static /Users/aakash/4333520/Worksheet4/calc_cmake/static/CMakeFiles/calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calc.dir/depend

