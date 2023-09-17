cmake_minimum_required(VERSION 3.24)
project(Linked_List C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Linked_List
        linked_list.c
        linked_list.h
        main.c)
