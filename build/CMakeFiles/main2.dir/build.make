# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = C:\opt\ros\foxy\x64\Lib\site-packages\cmake\data\bin\cmake.exe

# The command to remove a file.
RM = C:\opt\ros\foxy\x64\Lib\site-packages\cmake\data\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\ws\techical_test_ROS\rl_ws\src\rl_pkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\ws\techical_test_ROS\build

# Include any dependencies generated for this target.
include CMakeFiles/main2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main2.dir/flags.make

CMakeFiles/main2.dir/src/main2.cpp.obj: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/src/main2.cpp.obj: CMakeFiles/main2.dir/includes_CXX.rsp
CMakeFiles/main2.dir/src/main2.cpp.obj: C:/ws/techical_test_ROS/rl_ws/src/rl_pkg/src/main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\ws\techical_test_ROS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main2.dir/src/main2.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main2.dir\src\main2.cpp.obj -c C:\ws\techical_test_ROS\rl_ws\src\rl_pkg\src\main2.cpp

CMakeFiles/main2.dir/src/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main2.dir/src/main2.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\ws\techical_test_ROS\rl_ws\src\rl_pkg\src\main2.cpp > CMakeFiles\main2.dir\src\main2.cpp.i

CMakeFiles/main2.dir/src/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main2.dir/src/main2.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\ws\techical_test_ROS\rl_ws\src\rl_pkg\src\main2.cpp -o CMakeFiles\main2.dir\src\main2.cpp.s

# Object files for target main2
main2_OBJECTS = \
"CMakeFiles/main2.dir/src/main2.cpp.obj"

# External object files for target main2
main2_EXTERNAL_OBJECTS =

main2.exe: CMakeFiles/main2.dir/src/main2.cpp.obj
main2.exe: CMakeFiles/main2.dir/build.make
main2.exe: CMakeFiles/main2.dir/linklibs.rsp
main2.exe: CMakeFiles/main2.dir/objects1.rsp
main2.exe: CMakeFiles/main2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\ws\techical_test_ROS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main2.dir/build: main2.exe

.PHONY : CMakeFiles/main2.dir/build

CMakeFiles/main2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main2.dir/clean

CMakeFiles/main2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\ws\techical_test_ROS\rl_ws\src\rl_pkg C:\ws\techical_test_ROS\rl_ws\src\rl_pkg C:\ws\techical_test_ROS\build C:\ws\techical_test_ROS\build C:\ws\techical_test_ROS\build\CMakeFiles\main2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main2.dir/depend

