# Project definition
cmake_minimum_required(VERSION 3.2)

#GLFW
find_package(glfw3 REQUIRED)

#Source files
set(SOURCE_FILES 
    glfw_test.h 
    glfw_test.cpp 
    #GLAD
    $ENV{GLAD_DIR}/include/glad/glad.h 
    $ENV{GLAD_DIR}/src/glad.c)

add_library(glfw_test ${SOURCE_FILES})

target_link_libraries(glfw_test  glfw ${CMAKE_DL_LIBS})
#GLAD
target_include_directories(glfw_test 
    PUBLIC 
    $ENV{GLAD_DIR}/include
    $ENV{GLAD_DIR}/src)

#shaders setup
configure_file(frag_shader.frag ${CMAKE_CURRENT_BINARY_DIR}/frag_shader.frag COPYONLY)
configure_file(vertex_shader.vert ${CMAKE_CURRENT_BINARY_DIR}/vertex_shader.vert COPYONLY)

#main program build
set(SOURCE_FILES Main.cpp glfw_test.h)
# Executable definition and properties
add_executable(testgl ${SOURCE_FILES})
target_link_libraries(testgl glfw_test)