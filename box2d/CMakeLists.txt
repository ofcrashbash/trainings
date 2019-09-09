cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(unofficial-box2d CONFIG REQUIRED)

set(SOURCE_FILES 
    main.cpp)

add_executable(boxexample ${SOURCE_FILES})
target_link_libraries(boxexample PRIVATE unofficial::box2d::Box2D)