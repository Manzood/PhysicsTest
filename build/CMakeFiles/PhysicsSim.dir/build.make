# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/build

# Include any dependencies generated for this target.
include CMakeFiles/PhysicsSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PhysicsSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PhysicsSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PhysicsSim.dir/flags.make

CMakeFiles/PhysicsSim.dir/src/main.cpp.o: CMakeFiles/PhysicsSim.dir/flags.make
CMakeFiles/PhysicsSim.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/PhysicsSim.dir/src/main.cpp.o: CMakeFiles/PhysicsSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PhysicsSim.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PhysicsSim.dir/src/main.cpp.o -MF CMakeFiles/PhysicsSim.dir/src/main.cpp.o.d -o CMakeFiles/PhysicsSim.dir/src/main.cpp.o -c /app/src/main.cpp

CMakeFiles/PhysicsSim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhysicsSim.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/main.cpp > CMakeFiles/PhysicsSim.dir/src/main.cpp.i

CMakeFiles/PhysicsSim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhysicsSim.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/main.cpp -o CMakeFiles/PhysicsSim.dir/src/main.cpp.s

# Object files for target PhysicsSim
PhysicsSim_OBJECTS = \
"CMakeFiles/PhysicsSim.dir/src/main.cpp.o"

# External object files for target PhysicsSim
PhysicsSim_EXTERNAL_OBJECTS =

PhysicsSim: CMakeFiles/PhysicsSim.dir/src/main.cpp.o
PhysicsSim: CMakeFiles/PhysicsSim.dir/build.make
PhysicsSim: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
PhysicsSim: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
PhysicsSim: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
PhysicsSim: CMakeFiles/PhysicsSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PhysicsSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PhysicsSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PhysicsSim.dir/build: PhysicsSim
.PHONY : CMakeFiles/PhysicsSim.dir/build

CMakeFiles/PhysicsSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PhysicsSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PhysicsSim.dir/clean

CMakeFiles/PhysicsSim.dir/depend:
	cd /app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app /app /app/build /app/build /app/build/CMakeFiles/PhysicsSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PhysicsSim.dir/depend

