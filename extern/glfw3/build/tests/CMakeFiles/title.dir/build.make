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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/Vaibhav/Downloads/glfw-3.3.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/Vaibhav/Downloads/glfw-3.3.7/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/title.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/title.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/title.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/title.dir/flags.make

tests/CMakeFiles/title.dir/title.c.obj: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/title.c.obj: tests/CMakeFiles/title.dir/includes_C.rsp
tests/CMakeFiles/title.dir/title.c.obj: ../tests/title.c
tests/CMakeFiles/title.dir/title.c.obj: tests/CMakeFiles/title.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/title.dir/title.c.obj"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/title.dir/title.c.obj -MF CMakeFiles/title.dir/title.c.obj.d -o CMakeFiles/title.dir/title.c.obj -c C:/Users/Vaibhav/Downloads/glfw-3.3.7/tests/title.c

tests/CMakeFiles/title.dir/title.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/title.c.i"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/Vaibhav/Downloads/glfw-3.3.7/tests/title.c > CMakeFiles/title.dir/title.c.i

tests/CMakeFiles/title.dir/title.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/title.c.s"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/Vaibhav/Downloads/glfw-3.3.7/tests/title.c -o CMakeFiles/title.dir/title.c.s

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/title.dir/includes_C.rsp
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: ../deps/glad_gl.c
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/title.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj -MF CMakeFiles/title.dir/__/deps/glad_gl.c.obj.d -o CMakeFiles/title.dir/__/deps/glad_gl.c.obj -c C:/Users/Vaibhav/Downloads/glfw-3.3.7/deps/glad_gl.c

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/__/deps/glad_gl.c.i"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/Vaibhav/Downloads/glfw-3.3.7/deps/glad_gl.c > CMakeFiles/title.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/__/deps/glad_gl.c.s"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/Vaibhav/Downloads/glfw-3.3.7/deps/glad_gl.c -o CMakeFiles/title.dir/__/deps/glad_gl.c.s

# Object files for target title
title_OBJECTS = \
"CMakeFiles/title.dir/title.c.obj" \
"CMakeFiles/title.dir/__/deps/glad_gl.c.obj"

# External object files for target title
title_EXTERNAL_OBJECTS =

tests/title.exe: tests/CMakeFiles/title.dir/title.c.obj
tests/title.exe: tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj
tests/title.exe: tests/CMakeFiles/title.dir/build.make
tests/title.exe: src/libglfw3.a
tests/title.exe: tests/CMakeFiles/title.dir/linklibs.rsp
tests/title.exe: tests/CMakeFiles/title.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable title.exe"
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/title.dir/objects.a
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/ar.exe qc CMakeFiles/title.dir/objects.a @CMakeFiles/title.dir/objects1.rsp
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && C:/ProgramData/chocolatey/bin/gcc.exe -mwindows -Wl,--whole-archive CMakeFiles/title.dir/objects.a -Wl,--no-whole-archive -o title.exe -Wl,--out-implib,libtitle.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/title.dir/linklibs.rsp

# Rule to build all files generated by this target.
tests/CMakeFiles/title.dir/build: tests/title.exe
.PHONY : tests/CMakeFiles/title.dir/build

tests/CMakeFiles/title.dir/clean:
	cd C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/title.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/title.dir/clean

tests/CMakeFiles/title.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/Vaibhav/Downloads/glfw-3.3.7 C:/Users/Vaibhav/Downloads/glfw-3.3.7/tests C:/Users/Vaibhav/Downloads/glfw-3.3.7/build C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests C:/Users/Vaibhav/Downloads/glfw-3.3.7/build/tests/CMakeFiles/title.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/title.dir/depend

