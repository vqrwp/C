cmake_minimum_required(VERSION 3.10)
project(lab_10 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_10 main.c popfront.c popfront.h popend.c popend.h append.c append.h insert_sort.c
        insert_sort.h struct.h read_list.c read_list.h list_funcs.c list_funcs.h push.c push.h menu.c menu.h)


add_executable(lab_10_test tests.c popfront.c popfront.h popend.c popend.h append.c append.h insert_sort.c
        insert_sort.h struct.h read_list.c read_list.h list_funcs.c list_funcs.h push.c push.h menu.c menu.h
        popfronttest.c popfronttest.h popbacktest.c popbacktest.h appendtest.c appendtest.h sorttest.c sorttest.h)