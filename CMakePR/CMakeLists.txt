cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp)

if(WIN32)
    set(SOURCE_FILES "${SOURCE_FILES}" winsupport.cpp)
else()
    set(SOURCE_FILES "${SOURCE_FILES}" linuxsupport.cpp)
endif()

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(OPENGL_FOUND)
    message("OpenGL found")
endif()


find_library(GMSH_LIBRARY
NAMES libgmsh.a
PATHS /usr/local/gmsh/lib)

if(GMSH_LIBRARY)
    message("GMSH!")    
    target_link_libraries(hello ${GMSH_LIBRARY})
endif()

add_executable(hello ${SOURCE_FILES})