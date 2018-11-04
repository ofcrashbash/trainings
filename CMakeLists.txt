cmake_minimum_required(VERSION 3.2)

project(trainings C CXX)

add_subdirectory(OpenGLC)
add_subdirectory(CUDA)
add_subdirectory(Trainings)
#FIXME: for some reason c++17 doesn't copiles in this folder
#add_subdirectory(STL_Book) 