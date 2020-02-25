cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(deal.II 9.1.0 REQUIRED
    HINTS /mnt/c/users/ofcra/Lib/dealii_d_shared
    )
deal_ii_initialize_cached_variables()

add_executable(main main.cpp)

add_library(step1 step-1.hpp step-1.cpp)
deal_ii_setup_target(step1)

add_library(step2 step-2.hpp step-2.cpp)
deal_ii_setup_target(step2)

add_library(step3 step-3.hpp step-3.cpp)
deal_ii_setup_target(step3)

target_link_libraries(main step1 step2 step3)
deal_ii_setup_target(main)