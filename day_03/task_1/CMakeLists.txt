project(day_03)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)

add_library(pn-lib gear_ratios.cpp)
add_executable(part_numbers main.cpp)
target_link_libraries(part_numbers pn-lib)