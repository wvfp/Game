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
include Application/CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Application/CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include Application/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include Application/CMakeFiles/app.dir/flags.make

Application/CMakeFiles/app.dir/Application.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/Application.cpp.o: /home/wvfp/Projects/Game/Application/Application.cpp
Application/CMakeFiles/app.dir/Application.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Application/CMakeFiles/app.dir/Application.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/Application.cpp.o -MF CMakeFiles/app.dir/Application.cpp.o.d -o CMakeFiles/app.dir/Application.cpp.o -c /home/wvfp/Projects/Game/Application/Application.cpp

Application/CMakeFiles/app.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/Application.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/Application.cpp > CMakeFiles/app.dir/Application.cpp.i

Application/CMakeFiles/app.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/Application.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/Application.cpp -o CMakeFiles/app.dir/Application.cpp.s

Application/CMakeFiles/app.dir/FPSControler.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/FPSControler.cpp.o: /home/wvfp/Projects/Game/Application/FPSControler.cpp
Application/CMakeFiles/app.dir/FPSControler.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Application/CMakeFiles/app.dir/FPSControler.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/FPSControler.cpp.o -MF CMakeFiles/app.dir/FPSControler.cpp.o.d -o CMakeFiles/app.dir/FPSControler.cpp.o -c /home/wvfp/Projects/Game/Application/FPSControler.cpp

Application/CMakeFiles/app.dir/FPSControler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/FPSControler.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/FPSControler.cpp > CMakeFiles/app.dir/FPSControler.cpp.i

Application/CMakeFiles/app.dir/FPSControler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/FPSControler.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/FPSControler.cpp -o CMakeFiles/app.dir/FPSControler.cpp.s

Application/CMakeFiles/app.dir/Label.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/Label.cpp.o: /home/wvfp/Projects/Game/Application/Label.cpp
Application/CMakeFiles/app.dir/Label.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Application/CMakeFiles/app.dir/Label.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/Label.cpp.o -MF CMakeFiles/app.dir/Label.cpp.o.d -o CMakeFiles/app.dir/Label.cpp.o -c /home/wvfp/Projects/Game/Application/Label.cpp

Application/CMakeFiles/app.dir/Label.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/Label.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/Label.cpp > CMakeFiles/app.dir/Label.cpp.i

Application/CMakeFiles/app.dir/Label.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/Label.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/Label.cpp -o CMakeFiles/app.dir/Label.cpp.s

Application/CMakeFiles/app.dir/PushButton.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/PushButton.cpp.o: /home/wvfp/Projects/Game/Application/PushButton.cpp
Application/CMakeFiles/app.dir/PushButton.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Application/CMakeFiles/app.dir/PushButton.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/PushButton.cpp.o -MF CMakeFiles/app.dir/PushButton.cpp.o.d -o CMakeFiles/app.dir/PushButton.cpp.o -c /home/wvfp/Projects/Game/Application/PushButton.cpp

Application/CMakeFiles/app.dir/PushButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/PushButton.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/PushButton.cpp > CMakeFiles/app.dir/PushButton.cpp.i

Application/CMakeFiles/app.dir/PushButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/PushButton.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/PushButton.cpp -o CMakeFiles/app.dir/PushButton.cpp.s

Application/CMakeFiles/app.dir/Texture.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/Texture.cpp.o: /home/wvfp/Projects/Game/Application/Texture.cpp
Application/CMakeFiles/app.dir/Texture.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Application/CMakeFiles/app.dir/Texture.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/Texture.cpp.o -MF CMakeFiles/app.dir/Texture.cpp.o.d -o CMakeFiles/app.dir/Texture.cpp.o -c /home/wvfp/Projects/Game/Application/Texture.cpp

Application/CMakeFiles/app.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/Texture.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/Texture.cpp > CMakeFiles/app.dir/Texture.cpp.i

Application/CMakeFiles/app.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/Texture.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/Texture.cpp -o CMakeFiles/app.dir/Texture.cpp.s

Application/CMakeFiles/app.dir/Widget.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/Widget.cpp.o: /home/wvfp/Projects/Game/Application/Widget.cpp
Application/CMakeFiles/app.dir/Widget.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Application/CMakeFiles/app.dir/Widget.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/Widget.cpp.o -MF CMakeFiles/app.dir/Widget.cpp.o.d -o CMakeFiles/app.dir/Widget.cpp.o -c /home/wvfp/Projects/Game/Application/Widget.cpp

Application/CMakeFiles/app.dir/Widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/Widget.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/Widget.cpp > CMakeFiles/app.dir/Widget.cpp.i

Application/CMakeFiles/app.dir/Widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/Widget.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/Widget.cpp -o CMakeFiles/app.dir/Widget.cpp.s

Application/CMakeFiles/app.dir/WidgetMaker.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/WidgetMaker.cpp.o: /home/wvfp/Projects/Game/Application/WidgetMaker.cpp
Application/CMakeFiles/app.dir/WidgetMaker.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Application/CMakeFiles/app.dir/WidgetMaker.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/WidgetMaker.cpp.o -MF CMakeFiles/app.dir/WidgetMaker.cpp.o.d -o CMakeFiles/app.dir/WidgetMaker.cpp.o -c /home/wvfp/Projects/Game/Application/WidgetMaker.cpp

Application/CMakeFiles/app.dir/WidgetMaker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/WidgetMaker.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/WidgetMaker.cpp > CMakeFiles/app.dir/WidgetMaker.cpp.i

Application/CMakeFiles/app.dir/WidgetMaker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/WidgetMaker.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/WidgetMaker.cpp -o CMakeFiles/app.dir/WidgetMaker.cpp.s

Application/CMakeFiles/app.dir/tinyxml2.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/tinyxml2.cpp.o: /home/wvfp/Projects/Game/Application/tinyxml2.cpp
Application/CMakeFiles/app.dir/tinyxml2.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Application/CMakeFiles/app.dir/tinyxml2.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/tinyxml2.cpp.o -MF CMakeFiles/app.dir/tinyxml2.cpp.o.d -o CMakeFiles/app.dir/tinyxml2.cpp.o -c /home/wvfp/Projects/Game/Application/tinyxml2.cpp

Application/CMakeFiles/app.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/tinyxml2.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/tinyxml2.cpp > CMakeFiles/app.dir/tinyxml2.cpp.i

Application/CMakeFiles/app.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/tinyxml2.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/tinyxml2.cpp -o CMakeFiles/app.dir/tinyxml2.cpp.s

Application/CMakeFiles/app.dir/tools.cpp.o: Application/CMakeFiles/app.dir/flags.make
Application/CMakeFiles/app.dir/tools.cpp.o: /home/wvfp/Projects/Game/Application/tools.cpp
Application/CMakeFiles/app.dir/tools.cpp.o: Application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Application/CMakeFiles/app.dir/tools.cpp.o"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Application/CMakeFiles/app.dir/tools.cpp.o -MF CMakeFiles/app.dir/tools.cpp.o.d -o CMakeFiles/app.dir/tools.cpp.o -c /home/wvfp/Projects/Game/Application/tools.cpp

Application/CMakeFiles/app.dir/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/tools.cpp.i"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wvfp/Projects/Game/Application/tools.cpp > CMakeFiles/app.dir/tools.cpp.i

Application/CMakeFiles/app.dir/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/tools.cpp.s"
	cd /home/wvfp/Projects/Game/build/Application && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wvfp/Projects/Game/Application/tools.cpp -o CMakeFiles/app.dir/tools.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/Application.cpp.o" \
"CMakeFiles/app.dir/FPSControler.cpp.o" \
"CMakeFiles/app.dir/Label.cpp.o" \
"CMakeFiles/app.dir/PushButton.cpp.o" \
"CMakeFiles/app.dir/Texture.cpp.o" \
"CMakeFiles/app.dir/Widget.cpp.o" \
"CMakeFiles/app.dir/WidgetMaker.cpp.o" \
"CMakeFiles/app.dir/tinyxml2.cpp.o" \
"CMakeFiles/app.dir/tools.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

Application/libapp.a: Application/CMakeFiles/app.dir/Application.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/FPSControler.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/Label.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/PushButton.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/Texture.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/Widget.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/WidgetMaker.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/tinyxml2.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/tools.cpp.o
Application/libapp.a: Application/CMakeFiles/app.dir/build.make
Application/libapp.a: Application/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wvfp/Projects/Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libapp.a"
	cd /home/wvfp/Projects/Game/build/Application && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean_target.cmake
	cd /home/wvfp/Projects/Game/build/Application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Application/CMakeFiles/app.dir/build: Application/libapp.a
.PHONY : Application/CMakeFiles/app.dir/build

Application/CMakeFiles/app.dir/clean:
	cd /home/wvfp/Projects/Game/build/Application && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : Application/CMakeFiles/app.dir/clean

Application/CMakeFiles/app.dir/depend:
	cd /home/wvfp/Projects/Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wvfp/Projects/Game /home/wvfp/Projects/Game/Application /home/wvfp/Projects/Game/build /home/wvfp/Projects/Game/build/Application /home/wvfp/Projects/Game/build/Application/CMakeFiles/app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Application/CMakeFiles/app.dir/depend

