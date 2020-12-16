cmake_minimum_required(VERSION 3.12)
project(AlgorithmCourse)

set(CMAKE_CXX_STANDARD 14)

#添加动态/静态链接库lib
# link_directories("C:/Program Files (x86)/Intel/RSSDK/lib/x64")
#添加include目录
# include_directories("C:/Program Files (x86)/Intel/RSSDK/include")

add_executable(AlgorithmCourse Lab3/NQueens.cpp Lab3/NQueens.h)