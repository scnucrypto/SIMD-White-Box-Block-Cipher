# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ryanclq/code/self-equivalence/White-box-AES-SE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryanclq/code/self-equivalence/White-box-AES-SE/build

# Include any dependencies generated for this target.
include CMakeFiles/WBAES_SE_MS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WBAES_SE_MS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WBAES_SE_MS.dir/flags.make

CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o: CMakeFiles/WBAES_SE_MS.dir/flags.make
CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o: ../test/wbaes_se_ms_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryanclq/code/self-equivalence/White-box-AES-SE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o   -c /home/ryanclq/code/self-equivalence/White-box-AES-SE/test/wbaes_se_ms_test.c

CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryanclq/code/self-equivalence/White-box-AES-SE/test/wbaes_se_ms_test.c > CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.i

CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryanclq/code/self-equivalence/White-box-AES-SE/test/wbaes_se_ms_test.c -o CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.s

# Object files for target WBAES_SE_MS
WBAES_SE_MS_OBJECTS = \
"CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o"

# External object files for target WBAES_SE_MS
WBAES_SE_MS_EXTERNAL_OBJECTS =

WBAES_SE_MS: CMakeFiles/WBAES_SE_MS.dir/test/wbaes_se_ms_test.c.o
WBAES_SE_MS: CMakeFiles/WBAES_SE_MS.dir/build.make
WBAES_SE_MS: libWBAES_SE_LIB.a
WBAES_SE_MS: CMakeFiles/WBAES_SE_MS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ryanclq/code/self-equivalence/White-box-AES-SE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable WBAES_SE_MS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WBAES_SE_MS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WBAES_SE_MS.dir/build: WBAES_SE_MS

.PHONY : CMakeFiles/WBAES_SE_MS.dir/build

CMakeFiles/WBAES_SE_MS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WBAES_SE_MS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WBAES_SE_MS.dir/clean

CMakeFiles/WBAES_SE_MS.dir/depend:
	cd /home/ryanclq/code/self-equivalence/White-box-AES-SE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryanclq/code/self-equivalence/White-box-AES-SE /home/ryanclq/code/self-equivalence/White-box-AES-SE /home/ryanclq/code/self-equivalence/White-box-AES-SE/build /home/ryanclq/code/self-equivalence/White-box-AES-SE/build /home/ryanclq/code/self-equivalence/White-box-AES-SE/build/CMakeFiles/WBAES_SE_MS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WBAES_SE_MS.dir/depend
