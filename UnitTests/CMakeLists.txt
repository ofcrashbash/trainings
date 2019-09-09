cmake_minimum_required(VERSION 3.0)

# todo what is location will be changed

set(MS_UNIT_TEST_INCLUDE_FOLDER 
    "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/UnitTest/include" 
    CACHE 
    PATH 
    "Path to include files of Microsoft Unit Test Framework")

set(MS_UNIT_TEST_LIB_FOLDER 
    "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/UnitTest/lib/x64/Microsoft.VisualStudio.TestTools.CppUnitTestFramework.lib"
    CACHE 
    FILEPATH 
    "Path to library file of Microsoft Unit Test Framework")

include_directories(${MS_UNIT_TEST_INCLUDE_FOLDER})
link_directories(${MS_UNIT_TEST_LIB_FOLDER})

add_library(tests SHARED 
    eulerproject.cpp 
    stdafx.h stdafx.cpp targetver.h)

message("Use Visual Studio Test Explorer To Run Tests")