# Project definition
cmake_minimum_required(VERSION 3.2)
project(InitGL CXX)


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
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES ${SRC_DIR}/main.cpp ${GLAD_DIR}/include/glad/glad ${GLFW_DIR}/include/GLFW/glfw3)


# Executable definition and properties
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${GLFW_LIB} ${GLAD_LIB} ${GL_LIBRARY} m pthread ${CMAKE_DL_LIBS})
#target_link_libraries(${PROJECT_NAME}  )
#target_link_libraries(${PROJECT_NAME} ) #order matters!
