cmake_minimum_required(VERSION 3.0)

project(trainings C CXX)

# for some reason it doesn't work
if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
    set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}" CACHE STRING "")
else()
    set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}" CACHE STRING "")
endif()

set(BUILD_SHARED_LIBS OFF)


add_subdirectory(box2d)
add_subdirectory(C++17)
add_subdirectory(CMakePR)
add_subdirectory(OpenGL)
add_subdirectory(OpenCV)
add_subdirectory(CUDA)
add_subdirectory(EulerProject)
add_subdirectory(EulerRunner)
add_subdirectory(STLBook) 
add_subdirectory(UnitTests)