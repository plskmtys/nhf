# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matyas/sata/code/prog1/nhf/nhf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matyas/sata/code/prog1/nhf/nhf/build

# Include any dependencies generated for this target.
include CMakeFiles/nhf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nhf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nhf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nhf.dir/flags.make

CMakeFiles/nhf.dir/func_test.c.o: CMakeFiles/nhf.dir/flags.make
CMakeFiles/nhf.dir/func_test.c.o: /home/matyas/sata/code/prog1/nhf/nhf/func_test.c
CMakeFiles/nhf.dir/func_test.c.o: CMakeFiles/nhf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nhf.dir/func_test.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nhf.dir/func_test.c.o -MF CMakeFiles/nhf.dir/func_test.c.o.d -o CMakeFiles/nhf.dir/func_test.c.o -c /home/matyas/sata/code/prog1/nhf/nhf/func_test.c

CMakeFiles/nhf.dir/func_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nhf.dir/func_test.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matyas/sata/code/prog1/nhf/nhf/func_test.c > CMakeFiles/nhf.dir/func_test.c.i

CMakeFiles/nhf.dir/func_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nhf.dir/func_test.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matyas/sata/code/prog1/nhf/nhf/func_test.c -o CMakeFiles/nhf.dir/func_test.c.s

CMakeFiles/nhf.dir/include/menu.c.o: CMakeFiles/nhf.dir/flags.make
CMakeFiles/nhf.dir/include/menu.c.o: /home/matyas/sata/code/prog1/nhf/nhf/include/menu.c
CMakeFiles/nhf.dir/include/menu.c.o: CMakeFiles/nhf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nhf.dir/include/menu.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nhf.dir/include/menu.c.o -MF CMakeFiles/nhf.dir/include/menu.c.o.d -o CMakeFiles/nhf.dir/include/menu.c.o -c /home/matyas/sata/code/prog1/nhf/nhf/include/menu.c

CMakeFiles/nhf.dir/include/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nhf.dir/include/menu.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matyas/sata/code/prog1/nhf/nhf/include/menu.c > CMakeFiles/nhf.dir/include/menu.c.i

CMakeFiles/nhf.dir/include/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nhf.dir/include/menu.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matyas/sata/code/prog1/nhf/nhf/include/menu.c -o CMakeFiles/nhf.dir/include/menu.c.s

CMakeFiles/nhf.dir/include/vcard.c.o: CMakeFiles/nhf.dir/flags.make
CMakeFiles/nhf.dir/include/vcard.c.o: /home/matyas/sata/code/prog1/nhf/nhf/include/vcard.c
CMakeFiles/nhf.dir/include/vcard.c.o: CMakeFiles/nhf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/nhf.dir/include/vcard.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nhf.dir/include/vcard.c.o -MF CMakeFiles/nhf.dir/include/vcard.c.o.d -o CMakeFiles/nhf.dir/include/vcard.c.o -c /home/matyas/sata/code/prog1/nhf/nhf/include/vcard.c

CMakeFiles/nhf.dir/include/vcard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nhf.dir/include/vcard.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matyas/sata/code/prog1/nhf/nhf/include/vcard.c > CMakeFiles/nhf.dir/include/vcard.c.i

CMakeFiles/nhf.dir/include/vcard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nhf.dir/include/vcard.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matyas/sata/code/prog1/nhf/nhf/include/vcard.c -o CMakeFiles/nhf.dir/include/vcard.c.s

CMakeFiles/nhf.dir/include/lista.c.o: CMakeFiles/nhf.dir/flags.make
CMakeFiles/nhf.dir/include/lista.c.o: /home/matyas/sata/code/prog1/nhf/nhf/include/lista.c
CMakeFiles/nhf.dir/include/lista.c.o: CMakeFiles/nhf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/nhf.dir/include/lista.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nhf.dir/include/lista.c.o -MF CMakeFiles/nhf.dir/include/lista.c.o.d -o CMakeFiles/nhf.dir/include/lista.c.o -c /home/matyas/sata/code/prog1/nhf/nhf/include/lista.c

CMakeFiles/nhf.dir/include/lista.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nhf.dir/include/lista.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matyas/sata/code/prog1/nhf/nhf/include/lista.c > CMakeFiles/nhf.dir/include/lista.c.i

CMakeFiles/nhf.dir/include/lista.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nhf.dir/include/lista.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matyas/sata/code/prog1/nhf/nhf/include/lista.c -o CMakeFiles/nhf.dir/include/lista.c.s

# Object files for target nhf
nhf_OBJECTS = \
"CMakeFiles/nhf.dir/func_test.c.o" \
"CMakeFiles/nhf.dir/include/menu.c.o" \
"CMakeFiles/nhf.dir/include/vcard.c.o" \
"CMakeFiles/nhf.dir/include/lista.c.o"

# External object files for target nhf
nhf_EXTERNAL_OBJECTS =

/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/func_test.c.o
/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/include/menu.c.o
/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/include/vcard.c.o
/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/include/lista.c.o
/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/build.make
/home/matyas/sata/code/prog1/nhf/nhf/nhf: CMakeFiles/nhf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable /home/matyas/sata/code/prog1/nhf/nhf/nhf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nhf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nhf.dir/build: /home/matyas/sata/code/prog1/nhf/nhf/nhf
.PHONY : CMakeFiles/nhf.dir/build

CMakeFiles/nhf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nhf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nhf.dir/clean

CMakeFiles/nhf.dir/depend:
	cd /home/matyas/sata/code/prog1/nhf/nhf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matyas/sata/code/prog1/nhf/nhf /home/matyas/sata/code/prog1/nhf/nhf /home/matyas/sata/code/prog1/nhf/nhf/build /home/matyas/sata/code/prog1/nhf/nhf/build /home/matyas/sata/code/prog1/nhf/nhf/build/CMakeFiles/nhf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nhf.dir/depend

