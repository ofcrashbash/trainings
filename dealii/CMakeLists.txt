cmake_minimum_required(VERSION 3.10)

project(dealii_trainings DESCRIPTION "trainings with deal.ii library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(deal.II 9.1.0 REQUIRED
    HINTS /mnt/c/users/ofcra/Lib/dealii_d_shared
    )
deal_ii_initialize_cached_variables()

add_executable(main main.cpp)
#add_executable(main1 step-1-main.cpp)
#add_executable(main2 step-2-main.cpp)
#add_executable(main3 step-3-main.cpp)
#TODO not working for some reason

add_library(step1 step-1.hpp step-1.cpp)
add_library(step2 step-2.hpp step-2.cpp)
add_library(step3 step-3.hpp step-3.cpp)
#target_link_libraries(main1 step1)
#target_link_libraries(main2 step1 step2)
#target_link_libraries(main3 step1 step2 step3)
target_link_libraries(main step1 step2 step3)
deal_ii_setup_target(step1)
deal_ii_setup_target(step2)
deal_ii_setup_target(step3)

#deal_ii_setup_target(main1)
#deal_ii_setup_target(main2)
#deal_ii_setup_target(main3)
deal_ii_setup_target(main)
