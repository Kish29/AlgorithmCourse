# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asus\CLionProjects\AlgorithmCourse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgorithmCourse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgorithmCourse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgorithmCourse.dir/flags.make

CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj: CMakeFiles/AlgorithmCourse.dir/flags.make
CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj: CMakeFiles/AlgorithmCourse.dir/includes_CXX.rsp
CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj: ../Homework_3/Solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AlgorithmCourse.dir\Homework_3\Solution.cpp.obj -c C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\Solution.cpp

CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\Solution.cpp > CMakeFiles\AlgorithmCourse.dir\Homework_3\Solution.cpp.i

CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\Solution.cpp -o CMakeFiles\AlgorithmCourse.dir\Homework_3\Solution.cpp.s

CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj: CMakeFiles/AlgorithmCourse.dir/flags.make
CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj: CMakeFiles/AlgorithmCourse.dir/includes_CXX.rsp
CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj: ../Homework_3/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AlgorithmCourse.dir\Homework_3\test.cpp.obj -c C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\test.cpp

CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\test.cpp > CMakeFiles\AlgorithmCourse.dir\Homework_3\test.cpp.i

CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\asus\CLionProjects\AlgorithmCourse\Homework_3\test.cpp -o CMakeFiles\AlgorithmCourse.dir\Homework_3\test.cpp.s

# Object files for target AlgorithmCourse
AlgorithmCourse_OBJECTS = \
"CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj" \
"CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj"

# External object files for target AlgorithmCourse
AlgorithmCourse_EXTERNAL_OBJECTS =

AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/Homework_3/Solution.cpp.obj
AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/Homework_3/test.cpp.obj
AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/build.make
AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/linklibs.rsp
AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/objects1.rsp
AlgorithmCourse.exe: CMakeFiles/AlgorithmCourse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AlgorithmCourse.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AlgorithmCourse.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgorithmCourse.dir/build: AlgorithmCourse.exe

.PHONY : CMakeFiles/AlgorithmCourse.dir/build

CMakeFiles/AlgorithmCourse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AlgorithmCourse.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AlgorithmCourse.dir/clean

CMakeFiles/AlgorithmCourse.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\asus\CLionProjects\AlgorithmCourse C:\Users\asus\CLionProjects\AlgorithmCourse C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug C:\Users\asus\CLionProjects\AlgorithmCourse\cmake-build-debug\CMakeFiles\AlgorithmCourse.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgorithmCourse.dir/depend

