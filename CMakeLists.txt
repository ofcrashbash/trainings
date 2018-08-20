# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeProject")

set (CMakeProject_VERSION_MAJOR 1)
set (CMakeProject_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source

configure_file (
"${PROJECT_SOURCE_DIR}/CMakeProject/CMakeProjectConfig.h.in"
"${PROJECT_BINARY_DIR}/CMakeProject/CMakeProjectConfig.h"
)

# include_directories("${PROJECT_BINARY_DIR}/CMakeProject")


# Include sub-projects.
add_subdirectory ("CMakeProject")
