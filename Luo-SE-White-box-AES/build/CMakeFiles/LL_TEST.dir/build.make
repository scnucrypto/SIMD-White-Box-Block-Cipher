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
CMAKE_SOURCE_DIR = /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build

# Include any dependencies generated for this target.
include CMakeFiles/LL_TEST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LL_TEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LL_TEST.dir/flags.make

CMakeFiles/LL_TEST.dir/test/LL_test.c.o: CMakeFiles/LL_TEST.dir/flags.make
CMakeFiles/LL_TEST.dir/test/LL_test.c.o: ../test/LL_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LL_TEST.dir/test/LL_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LL_TEST.dir/test/LL_test.c.o   -c /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/test/LL_test.c

CMakeFiles/LL_TEST.dir/test/LL_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LL_TEST.dir/test/LL_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/test/LL_test.c > CMakeFiles/LL_TEST.dir/test/LL_test.c.i

CMakeFiles/LL_TEST.dir/test/LL_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LL_TEST.dir/test/LL_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/test/LL_test.c -o CMakeFiles/LL_TEST.dir/test/LL_test.c.s

# Object files for target LL_TEST
LL_TEST_OBJECTS = \
"CMakeFiles/LL_TEST.dir/test/LL_test.c.o"

# External object files for target LL_TEST
LL_TEST_EXTERNAL_OBJECTS =

LL_TEST: CMakeFiles/LL_TEST.dir/test/LL_test.c.o
LL_TEST: CMakeFiles/LL_TEST.dir/build.make
LL_TEST: libWBAES_SE_LIB.a
LL_TEST: CMakeFiles/LL_TEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LL_TEST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LL_TEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LL_TEST.dir/build: LL_TEST

.PHONY : CMakeFiles/LL_TEST.dir/build

CMakeFiles/LL_TEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LL_TEST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LL_TEST.dir/clean

CMakeFiles/LL_TEST.dir/depend:
	cd /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build /home/ryanclq/code/SIMD-White-Box-Block-Cipher/Luo-SE-White-box-AES/build/CMakeFiles/LL_TEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LL_TEST.dir/depend

