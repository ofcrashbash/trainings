cmake_minimum_required(VERSION 3.2)

project(trainings C CXX)

set(BUILD_DIR ${CMAKE_HOME_DIRECTORY}/build)

add_subdirectory(OpenGL)
add_subdirectory(CUDA)
add_subdirectory(EulerProject)
add_subdirectory(CMakePR)
#FIXME: for some reason c++17 doesn't copiles in this folder
#add_subdirectory(STLBook) 