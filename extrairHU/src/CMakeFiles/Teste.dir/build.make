# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeferson/workspace/extrairHU/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeferson/workspace/extrairHU/src

# Include any dependencies generated for this target.
include CMakeFiles/Teste.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Teste.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Teste.dir/flags.make

CMakeFiles/Teste.dir/main.o: CMakeFiles/Teste.dir/flags.make
CMakeFiles/Teste.dir/main.o: main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jeferson/workspace/extrairHU/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Teste.dir/main.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Teste.dir/main.o   -c /home/jeferson/workspace/extrairHU/src/main.c

CMakeFiles/Teste.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Teste.dir/main.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jeferson/workspace/extrairHU/src/main.c > CMakeFiles/Teste.dir/main.i

CMakeFiles/Teste.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Teste.dir/main.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jeferson/workspace/extrairHU/src/main.c -o CMakeFiles/Teste.dir/main.s

CMakeFiles/Teste.dir/main.o.requires:
.PHONY : CMakeFiles/Teste.dir/main.o.requires

CMakeFiles/Teste.dir/main.o.provides: CMakeFiles/Teste.dir/main.o.requires
	$(MAKE) -f CMakeFiles/Teste.dir/build.make CMakeFiles/Teste.dir/main.o.provides.build
.PHONY : CMakeFiles/Teste.dir/main.o.provides

CMakeFiles/Teste.dir/main.o.provides.build: CMakeFiles/Teste.dir/main.o
.PHONY : CMakeFiles/Teste.dir/main.o.provides.build

# Object files for target Teste
Teste_OBJECTS = \
"CMakeFiles/Teste.dir/main.o"

# External object files for target Teste
Teste_EXTERNAL_OBJECTS =

Teste: CMakeFiles/Teste.dir/main.o
Teste: CMakeFiles/Teste.dir/build.make
Teste: CMakeFiles/Teste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable Teste"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Teste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Teste.dir/build: Teste
.PHONY : CMakeFiles/Teste.dir/build

CMakeFiles/Teste.dir/requires: CMakeFiles/Teste.dir/main.o.requires
.PHONY : CMakeFiles/Teste.dir/requires

CMakeFiles/Teste.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Teste.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Teste.dir/clean

CMakeFiles/Teste.dir/depend:
	cd /home/jeferson/workspace/extrairHU/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeferson/workspace/extrairHU/src /home/jeferson/workspace/extrairHU/src /home/jeferson/workspace/extrairHU/src /home/jeferson/workspace/extrairHU/src /home/jeferson/workspace/extrairHU/src/CMakeFiles/Teste.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Teste.dir/depend
