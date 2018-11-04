cmake_minimum_required(VERSION 2.6)
project(hello)

set(hello_src main.cpp main_new.cpp)

if(WIN32)
    set(hello_src "${hello_src}" winsupport.cpp)
else()
    set(hello_src "${hello_src}" linuxsupport.cpp)
endif()

add_executable(hello ${hello_src})

find_library(GMSH_LIBRARY
NAMES libgmsh.a
PATHS /usr/local/gmsh/lib)

if(GMSH_LIBRARY)
    message("GMSH!")
    target_link_libraries(hello ${GMSH_LIBRARY})
endif()