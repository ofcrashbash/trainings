cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(basicclasses STATIC
    basicclasses.cpp 
    basicclasses.h)

add_library(cpp STATIC
    c++.cpp 
    c++.h)

add_library(exceptions STATIC
    Exceptions.cpp 
    Exceptions.h)

add_library(friendshipandinheritance STATIC
    friendshipandinheritance.cpp 
    friendshipandinheritance.h)

add_library(typecasting STATIC
    typecasting.cpp 
    typecasting.h)

add_executable(cppmain main.cpp)
target_link_libraries(cppmain 
    typecasting 
    friendshipandinheritance 
    exceptions 
    cpp 
    basicclasses)

    