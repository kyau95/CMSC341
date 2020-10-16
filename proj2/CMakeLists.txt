cmake_minimum_required(VERSION 3.17)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj2
        bNode.cpp
        bNode.h
        bookTree.cpp
        bookTree.h
        data.txt
        main.cpp
        mytest.cpp
        wordTree.cpp
        wordTree.h)
