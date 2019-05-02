cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

add_library(euler TheEulerProject.cpp theEulerProject.h)

add_executable(eulerproject main.cpp)

target_link_libraries(eulerproject euler)