# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/artemmelnik/Documents/GitHub/project_quest_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quest_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quest_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quest_test.dir/flags.make

CMakeFiles/quest_test.dir/test.cpp.o: CMakeFiles/quest_test.dir/flags.make
CMakeFiles/quest_test.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quest_test.dir/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quest_test.dir/test.cpp.o -c /Users/artemmelnik/Documents/GitHub/project_quest_game/test.cpp

CMakeFiles/quest_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quest_test.dir/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/artemmelnik/Documents/GitHub/project_quest_game/test.cpp > CMakeFiles/quest_test.dir/test.cpp.i

CMakeFiles/quest_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quest_test.dir/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/artemmelnik/Documents/GitHub/project_quest_game/test.cpp -o CMakeFiles/quest_test.dir/test.cpp.s

CMakeFiles/quest_test.dir/func.cpp.o: CMakeFiles/quest_test.dir/flags.make
CMakeFiles/quest_test.dir/func.cpp.o: ../func.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/quest_test.dir/func.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quest_test.dir/func.cpp.o -c /Users/artemmelnik/Documents/GitHub/project_quest_game/func.cpp

CMakeFiles/quest_test.dir/func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quest_test.dir/func.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/artemmelnik/Documents/GitHub/project_quest_game/func.cpp > CMakeFiles/quest_test.dir/func.cpp.i

CMakeFiles/quest_test.dir/func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quest_test.dir/func.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/artemmelnik/Documents/GitHub/project_quest_game/func.cpp -o CMakeFiles/quest_test.dir/func.cpp.s

# Object files for target quest_test
quest_test_OBJECTS = \
"CMakeFiles/quest_test.dir/test.cpp.o" \
"CMakeFiles/quest_test.dir/func.cpp.o"

# External object files for target quest_test
quest_test_EXTERNAL_OBJECTS =

quest_test: CMakeFiles/quest_test.dir/test.cpp.o
quest_test: CMakeFiles/quest_test.dir/func.cpp.o
quest_test: CMakeFiles/quest_test.dir/build.make
quest_test: /usr/local/lib/libsfml-graphics.2.5.1.dylib
quest_test: /usr/local/lib/libsfml-audio.2.5.1.dylib
quest_test: /usr/local/lib/libsfml-window.2.5.1.dylib
quest_test: /usr/local/lib/libsfml-system.2.5.1.dylib
quest_test: CMakeFiles/quest_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable quest_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quest_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quest_test.dir/build: quest_test

.PHONY : CMakeFiles/quest_test.dir/build

CMakeFiles/quest_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quest_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quest_test.dir/clean

CMakeFiles/quest_test.dir/depend:
	cd /Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/artemmelnik/Documents/GitHub/project_quest_game /Users/artemmelnik/Documents/GitHub/project_quest_game /Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug /Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug /Users/artemmelnik/Documents/GitHub/project_quest_game/cmake-build-debug/CMakeFiles/quest_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quest_test.dir/depend

