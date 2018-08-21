cmake_minimum_required (VERSION 2.6)
project (CmakeProject)

# The version number.
set (CMakeProject_VERSION_MAJOR 1)
set (CMakeProject_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
# TODO this config doenst generate header file!!

include_directories(${CMAKE_CURRENT_BINARY_DIR}/CMakeProject)

configure_file (
 "CMakeProject/CmakeProjectConfig.h.in"
 "CMakeProject/CmakeProjectConfig.h"
 @ONLY
)

# add the executable
add_executable(CmakeProject "CmakeProject/CmakeProject.cpp")