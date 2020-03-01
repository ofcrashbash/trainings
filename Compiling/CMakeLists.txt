cmake_minimum_required(VERSION 3.10)

project(compiler_test DESCRIPTION "ЯК правильно компілювати програму?" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(deal.II 9.1.0 REQUIRED
    HINTS /mnt/c/users/ofcra/Lib/dealii_d_shared
    )
deal_ii_initialize_cached_variables()

add_library(a a.hpp a.cpp)
add_executable(b b.hpp b.cpp)
target_link_libraries(b a)