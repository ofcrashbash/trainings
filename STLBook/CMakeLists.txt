cmake_minimum_required(VERSION 3.2)

project(stlbook CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stlbook stl_code.cpp stl_code.h)
