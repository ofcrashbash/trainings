cmake_minimum_required(VERSION 3.2)

project(eulerproject CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(euler TheEulerProject.cpp theEulerProject.h)

add_executable(eulerproject main.cpp)

target_link_libraries(eulerproject euler)