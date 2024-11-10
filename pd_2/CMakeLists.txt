cmake_minimum_required(VERSION 3.29)
project(lab_wdi C)

set(CMAKE_C_STANDARD 11)

include_directories(pd_2)

add_executable(lab_wdi
    pd_2/main.c)
