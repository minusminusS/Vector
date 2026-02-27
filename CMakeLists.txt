cmake_minimum_required(VERSION 4.0)
project(testVector)

set(CMAKE_CXX_STANDARD 20)

add_executable(testVector testVector.cpp
        vector.cpp
        vector.h)
