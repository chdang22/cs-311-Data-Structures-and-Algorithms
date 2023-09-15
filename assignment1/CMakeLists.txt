cmake_minimum_required(VERSION 3.24)
project(assignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(assignment1-main)

add_executable(t1
    assignment1-main/test1.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h)

add_executable(t2
        assignment1-main/test2.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h)

add_executable(t3
        assignment1-main/test3.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h)

add_executable(t02
        assignment1-main/test02.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h)

add_executable(assignment1
        assignment1-main/test1.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h
        assignment1-main/test2.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h
        assignment1-main/test3.cpp assignment1-main/linkedlist.cpp assignment1-main/linkedlist.h)