cmake_minimum_required(VERSION 3.10)
project(rk_04 C)

set(CMAKE_C_STANDARD 99)

add_executable(rk_04 main.c struct.h print.h print.c push_node.c push_node.h
        struct.h menu.c menu.h add_elem.c add_elem.h push_marks.c push_marks.h delete_node.c delete_node.h free.c free.h)