cmake_minimum_required(VERSION 3.24)
project(FIFO C)

set(CMAKE_C_STANDARD 90)

add_executable(FIFO main.c fifo.h fifo.c)
