# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build"

# Include any dependencies generated for this target.
include lib/CMakeFiles/libs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/libs.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/libs.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/libs.dir/flags.make

lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj: lib/CMakeFiles/libs.dir/flags.make
lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj: ../lib/Binary_Sort_Tree.cpp
lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj: lib/CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj -MF CMakeFiles\libs.dir\Binary_Sort_Tree.cpp.obj.d -o CMakeFiles\libs.dir\Binary_Sort_Tree.cpp.obj -c "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Sort_Tree.cpp"

lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.i"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Sort_Tree.cpp" > CMakeFiles\libs.dir\Binary_Sort_Tree.cpp.i

lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.s"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Sort_Tree.cpp" -o CMakeFiles\libs.dir\Binary_Sort_Tree.cpp.s

lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj: lib/CMakeFiles/libs.dir/flags.make
lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj: ../lib/Binary_Tree.cpp
lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj: lib/CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj -MF CMakeFiles\libs.dir\Binary_Tree.cpp.obj.d -o CMakeFiles\libs.dir\Binary_Tree.cpp.obj -c "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Tree.cpp"

lib/CMakeFiles/libs.dir/Binary_Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libs.dir/Binary_Tree.cpp.i"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Tree.cpp" > CMakeFiles\libs.dir\Binary_Tree.cpp.i

lib/CMakeFiles/libs.dir/Binary_Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libs.dir/Binary_Tree.cpp.s"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Binary_Tree.cpp" -o CMakeFiles\libs.dir\Binary_Tree.cpp.s

lib/CMakeFiles/libs.dir/Modules.cpp.obj: lib/CMakeFiles/libs.dir/flags.make
lib/CMakeFiles/libs.dir/Modules.cpp.obj: ../lib/Modules.cpp
lib/CMakeFiles/libs.dir/Modules.cpp.obj: lib/CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/CMakeFiles/libs.dir/Modules.cpp.obj"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/libs.dir/Modules.cpp.obj -MF CMakeFiles\libs.dir\Modules.cpp.obj.d -o CMakeFiles\libs.dir\Modules.cpp.obj -c "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Modules.cpp"

lib/CMakeFiles/libs.dir/Modules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libs.dir/Modules.cpp.i"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Modules.cpp" > CMakeFiles\libs.dir\Modules.cpp.i

lib/CMakeFiles/libs.dir/Modules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libs.dir/Modules.cpp.s"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && C:\MinGW\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib\Modules.cpp" -o CMakeFiles\libs.dir\Modules.cpp.s

# Object files for target libs
libs_OBJECTS = \
"CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj" \
"CMakeFiles/libs.dir/Binary_Tree.cpp.obj" \
"CMakeFiles/libs.dir/Modules.cpp.obj"

# External object files for target libs
libs_EXTERNAL_OBJECTS =

lib/liblibs.a: lib/CMakeFiles/libs.dir/Binary_Sort_Tree.cpp.obj
lib/liblibs.a: lib/CMakeFiles/libs.dir/Binary_Tree.cpp.obj
lib/liblibs.a: lib/CMakeFiles/libs.dir/Modules.cpp.obj
lib/liblibs.a: lib/CMakeFiles/libs.dir/build.make
lib/liblibs.a: lib/CMakeFiles/libs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library liblibs.a"
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && $(CMAKE_COMMAND) -P CMakeFiles\libs.dir\cmake_clean_target.cmake
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\libs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/libs.dir/build: lib/liblibs.a
.PHONY : lib/CMakeFiles/libs.dir/build

lib/CMakeFiles/libs.dir/clean:
	cd /d C:\Users\Varocol\Desktop\Cpp\202112~1\BINARY~1\build\lib && $(CMAKE_COMMAND) -P CMakeFiles\libs.dir\cmake_clean.cmake
.PHONY : lib/CMakeFiles/libs.dir/clean

lib/CMakeFiles/libs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree" "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\lib" "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build" "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\lib" "C:\Users\Varocol\Desktop\Cpp\20211207LessonDesign\Binary Sort Tree\build\lib\CMakeFiles\libs.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/libs.dir/depend

