cmake_minimum_required(VERSION 3.23)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms main.cpp)

target_include_directories(Algorithms PUBLIC problems/ data_structures/)