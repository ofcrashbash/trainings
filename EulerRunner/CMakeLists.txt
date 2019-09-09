cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories(../EulerProject/) #theEulerProject.h

add_executable(eulerrunner main.cpp ../EulerProject/theEulerProject.h)
target_link_libraries(eulerrunner euler)
target_include_directories(eulerrunner PUBLIC ../EulerProject/)