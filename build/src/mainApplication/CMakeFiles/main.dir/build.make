# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wvfp/Projects/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wvfp/Projects/Game/build

# Include any dependencies generated for this target.
include src/mainApplication/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/mainApplication/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/mainApplication/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/mainApplication/CMakeFiles/main.dir/flags.make

src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o: src/mainApplication/CMakeFiles/main.dir/flags.make
src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o: /home/wvfp/Projects/Game/src/mainApplication/mainApplication.cpp
src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o: src/mainApplication/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o"
	cd /home/wvfp/Projects/Game/build/src/mainApplication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o -MF CMakeFiles/main.dir/mainApplication.cpp.o.d -o CMakeFiles/main.dir/mainApplication.cpp.o -c /home/wvfp/Projects/Game/src/mainApplication/mainApplication.cpp

src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/mainApplication.cpp.i"
	cd /home/wvfp/Projects/Game/build/src/mainApplication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/src/mainApplication/mainApplication.cpp > CMakeFiles/main.dir/mainApplication.cpp.i

src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/mainApplication.cpp.s"
	cd /home/wvfp/Projects/Game/build/src/mainApplication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/src/mainApplication/mainApplication.cpp -o CMakeFiles/main.dir/mainApplication.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/mainApplication.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/mainApplication/libmain.a: src/mainApplication/CMakeFiles/main.dir/mainApplication.cpp.o
src/mainApplication/libmain.a: src/mainApplication/CMakeFiles/main.dir/build.make
src/mainApplication/libmain.a: src/mainApplication/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmain.a"
	cd /home/wvfp/Projects/Game/build/src/mainApplication && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean_target.cmake
	cd /home/wvfp/Projects/Game/build/src/mainApplication && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mainApplication/CMakeFiles/main.dir/build: src/mainApplication/libmain.a
.PHONY : src/mainApplication/CMakeFiles/main.dir/build

src/mainApplication/CMakeFiles/main.dir/clean:
	cd /home/wvfp/Projects/Game/build/src/mainApplication && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/mainApplication/CMakeFiles/main.dir/clean

src/mainApplication/CMakeFiles/main.dir/depend:
	cd /home/wvfp/Projects/Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wvfp/Projects/Game /home/wvfp/Projects/Game/src/mainApplication /home/wvfp/Projects/Game/build /home/wvfp/Projects/Game/build/src/mainApplication /home/wvfp/Projects/Game/build/src/mainApplication/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/mainApplication/CMakeFiles/main.dir/depend

