cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(deal.II 9.1.0 REQUIRED
    HINTS /mnt/c/users/ofcra/Lib/dealii_d_shared
    )
deal_ii_initialize_cached_variables()

add_executable(main steps.cpp)
deal_ii_setup_target(main)