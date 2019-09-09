cmake_minimum_required(VERSION 3.0)

find_package(OpenCV REQUIRED)

set(SOURCE_FILES Camera.cpp DisplayImage.cpp)
add_executable(opencv ${SOURCE_FILES})
target_link_libraries(opencv ${OpenCV_LIBS})