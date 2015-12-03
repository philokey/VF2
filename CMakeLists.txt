cmake_minimum_required(VERSION 3.3)
project(VF2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graph.cpp graph.h vf2.cpp vf2.h State.cpp State.h readData.cpp readData.h)
add_executable(VF2 ${SOURCE_FILES})