# Project definition
cmake_minimum_required(VERSION 3.2)
project(testgl CXX)


set(GLAD_DIR /usr/local/glad_debug)
set(GLFW_DIR /usr/local/glfw_debug)

include_directories(${PROJECT_NAME}    ${GLAD_DIR}/include)
include_directories(${PROJECT_NAME}    ${GLFW_DIR}/include)
find_library(GLAD_LIB libglad.a HINTS  ${GLAD_DIR}/lib)
find_library(GLFW_LIB libglfw3.a HINTS ${GLFW_DIR}/lib)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif()
set(GL_LIBRARY GL GLU X11)


# Source files
set(SOURCE_FILES Main.cpp ${GLAD_DIR}/include/glad/glad ${GLFW_DIR}/include/GLFW/glfw3)

add_library(glfw_test glfw_test.h glfw_test.cpp )
target_link_libraries(glfw_test ${GLFW_LIB} ${GLAD_LIB} ${GL_LIBRARY} m pthread ${CMAKE_DL_LIBS})
# Executable definition and properties
add_executable(testgl ${SOURCE_FILES})
target_link_libraries(testgl glfw_test)

message("installing to ${BUILD_DIR}/OpenGL")
file(COPY vertex_shader.vert
    DESTINATION ${BUILD_DIR}/OpenGL)
file(COPY frag_shader.frag
    DESTINATION ${BUILD_DIR}/OpenGL)

