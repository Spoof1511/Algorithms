# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Alan\Desktop\sumofitspartsDZ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sumofitspartsDZ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sumofitspartsDZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sumofitspartsDZ.dir/flags.make

CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj: CMakeFiles/sumofitspartsDZ.dir/flags.make
CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sumofitspartsDZ.dir\main.cpp.obj -c C:\Users\Alan\Desktop\sumofitspartsDZ\main.cpp

CMakeFiles/sumofitspartsDZ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sumofitspartsDZ.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alan\Desktop\sumofitspartsDZ\main.cpp > CMakeFiles\sumofitspartsDZ.dir\main.cpp.i

CMakeFiles/sumofitspartsDZ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sumofitspartsDZ.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alan\Desktop\sumofitspartsDZ\main.cpp -o CMakeFiles\sumofitspartsDZ.dir\main.cpp.s

CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.requires

CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.provides: CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sumofitspartsDZ.dir\build.make CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.provides

CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.provides.build: CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj


CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj: CMakeFiles/sumofitspartsDZ.dir/flags.make
CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj: ../parts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sumofitspartsDZ.dir\parts.cpp.obj -c C:\Users\Alan\Desktop\sumofitspartsDZ\parts.cpp

CMakeFiles/sumofitspartsDZ.dir/parts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sumofitspartsDZ.dir/parts.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alan\Desktop\sumofitspartsDZ\parts.cpp > CMakeFiles\sumofitspartsDZ.dir\parts.cpp.i

CMakeFiles/sumofitspartsDZ.dir/parts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sumofitspartsDZ.dir/parts.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alan\Desktop\sumofitspartsDZ\parts.cpp -o CMakeFiles\sumofitspartsDZ.dir\parts.cpp.s

CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.requires:

.PHONY : CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.requires

CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.provides: CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sumofitspartsDZ.dir\build.make CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.provides.build
.PHONY : CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.provides

CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.provides.build: CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj


# Object files for target sumofitspartsDZ
sumofitspartsDZ_OBJECTS = \
"CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj" \
"CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj"

# External object files for target sumofitspartsDZ
sumofitspartsDZ_EXTERNAL_OBJECTS =

sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj
sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj
sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/build.make
sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/linklibs.rsp
sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/objects1.rsp
sumofitspartsDZ.exe: CMakeFiles/sumofitspartsDZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sumofitspartsDZ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sumofitspartsDZ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sumofitspartsDZ.dir/build: sumofitspartsDZ.exe

.PHONY : CMakeFiles/sumofitspartsDZ.dir/build

CMakeFiles/sumofitspartsDZ.dir/requires: CMakeFiles/sumofitspartsDZ.dir/main.cpp.obj.requires
CMakeFiles/sumofitspartsDZ.dir/requires: CMakeFiles/sumofitspartsDZ.dir/parts.cpp.obj.requires

.PHONY : CMakeFiles/sumofitspartsDZ.dir/requires

CMakeFiles/sumofitspartsDZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sumofitspartsDZ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sumofitspartsDZ.dir/clean

CMakeFiles/sumofitspartsDZ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Alan\Desktop\sumofitspartsDZ C:\Users\Alan\Desktop\sumofitspartsDZ C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug C:\Users\Alan\Desktop\sumofitspartsDZ\cmake-build-debug\CMakeFiles\sumofitspartsDZ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sumofitspartsDZ.dir/depend

