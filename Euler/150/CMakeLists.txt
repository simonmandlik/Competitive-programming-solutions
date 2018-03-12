cmake_minimum_required(VERSION 3.6)
project(150)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(150 ${SOURCE_FILES})