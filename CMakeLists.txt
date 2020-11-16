cmake_minimum_required(VERSION 3.16)
project(AlgorithmCourse)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework_1)

add_executable(AlgorithmCourse Homework_3/Solution.cpp Homework_3/Solution.h Homework_3/test.cpp)