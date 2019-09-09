cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    main.cpp)

find_package(unofficial-box2d CONFIG)
if(unofficial-box2d_FOUND)
    add_executable(boxexample ${SOURCE_FILES})
    target_link_libraries(boxexample PRIVATE unofficial::box2d::Box2D)
else()
    find_package(Box2D CONFIG REQUIRED)

    add_executable(boxexample ${SOURCE_FILES})
    target_link_libraries(boxexample PRIVATE Box2D)
    
endif(unofficial-box2d_FOUND)