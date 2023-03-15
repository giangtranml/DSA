cmake_minimum_required(VERSION 3.23)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA main.cpp)

target_include_directories(DSA PUBLIC problems/ data_structures/)