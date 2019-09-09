cmake_minimum_required(VERSION 3.0)

#GLFW
find_package(glfw3 CONFIG REQUIRED)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    #Source files
    set(SOURCE_FILES 
        glfw_test.h 
        glfw_test.cpp 
        #GLAD
        $ENV{GLAD_DIR}/include/glad/glad.h 
        $ENV{GLAD_DIR}/src/glad.c)
        add_library(glfw_test ${SOURCE_FILES})

    target_link_libraries(glfw_test PRIVATE glfw ${CMAKE_DL_LIBS})
    #GLAD
    target_include_directories(glfw_test 
        PUBLIC 
        $ENV{GLAD_DIR}/include
        $ENV{GLAD_DIR}/src)

    
    #main program build
    set(SOURCE_FILES Main.cpp glfw_test.h)
    # Executable definition and properties
    add_executable(testgl ${SOURCE_FILES})
    target_link_libraries(testgl glfw_test)

#VCPKG case
elseif(DEFINED CMAKE_TOOLCHAIN_FILE)
    find_package(glad CONFIG REQUIRED)

    add_library(glfw_test glfw_test.h glfw_test.cpp)
    target_link_libraries(glfw_test PRIVATE glfw glad::glad)

    add_executable(glfw_main Main.cpp glfw_test.h)
    target_link_libraries(glfw_main PRIVATE glfw glfw_test)
endif(NOT DEFINED CMAKE_TOOLCHAIN_FILE)

#shaders setup
configure_file(frag_shader.frag ${CMAKE_CURRENT_BINARY_DIR}/frag_shader.frag COPYONLY)
configure_file(vertex_shader.vert ${CMAKE_CURRENT_BINARY_DIR}/vertex_shader.vert COPYONLY)
message("You have by HAND move shader files to folder where is binnary file!")