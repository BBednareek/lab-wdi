cmake_minimum_required(VERSION 3.29)
project(lab_wdi C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_wdi main.c
        includes/operations/operations.c
        includes/operations/operations.h
        includes/types/types.h
        includes/menu/menu.c
        includes/menu/menu.h)
