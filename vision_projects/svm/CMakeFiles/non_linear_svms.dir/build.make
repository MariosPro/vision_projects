# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marios/vision_projects/svm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marios/vision_projects/svm

# Include any dependencies generated for this target.
include CMakeFiles/non_linear_svms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/non_linear_svms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/non_linear_svms.dir/flags.make

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o: CMakeFiles/non_linear_svms.dir/flags.make
CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o: non_linear_svms.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marios/vision_projects/svm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o -c /home/marios/vision_projects/svm/non_linear_svms.cpp

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marios/vision_projects/svm/non_linear_svms.cpp > CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.i

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marios/vision_projects/svm/non_linear_svms.cpp -o CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.s

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.requires:
.PHONY : CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.requires

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.provides: CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.requires
	$(MAKE) -f CMakeFiles/non_linear_svms.dir/build.make CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.provides.build
.PHONY : CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.provides

CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.provides.build: CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o

# Object files for target non_linear_svms
non_linear_svms_OBJECTS = \
"CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o"

# External object files for target non_linear_svms
non_linear_svms_EXTERNAL_OBJECTS =

non_linear_svms: CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o
non_linear_svms: /opt/ros/hydro/lib/libopencv_videostab.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_video.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_ts.a
non_linear_svms: /opt/ros/hydro/lib/libopencv_superres.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_stitching.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_photo.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_ocl.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_objdetect.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_nonfree.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_ml.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_legacy.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_imgproc.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_highgui.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_gpu.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_flann.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_features2d.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_core.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_contrib.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_calib3d.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_nonfree.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_ocl.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_gpu.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_photo.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_objdetect.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_legacy.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_video.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_ml.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_calib3d.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_features2d.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_highgui.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_imgproc.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_flann.so.2.4.9
non_linear_svms: /opt/ros/hydro/lib/libopencv_core.so.2.4.9
non_linear_svms: CMakeFiles/non_linear_svms.dir/build.make
non_linear_svms: CMakeFiles/non_linear_svms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable non_linear_svms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/non_linear_svms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/non_linear_svms.dir/build: non_linear_svms
.PHONY : CMakeFiles/non_linear_svms.dir/build

CMakeFiles/non_linear_svms.dir/requires: CMakeFiles/non_linear_svms.dir/non_linear_svms.cpp.o.requires
.PHONY : CMakeFiles/non_linear_svms.dir/requires

CMakeFiles/non_linear_svms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/non_linear_svms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/non_linear_svms.dir/clean

CMakeFiles/non_linear_svms.dir/depend:
	cd /home/marios/vision_projects/svm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marios/vision_projects/svm /home/marios/vision_projects/svm /home/marios/vision_projects/svm /home/marios/vision_projects/svm /home/marios/vision_projects/svm/CMakeFiles/non_linear_svms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/non_linear_svms.dir/depend
