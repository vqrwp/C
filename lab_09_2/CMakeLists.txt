cmake_minimum_required(VERSION 3.10)
project(lab_09_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_09_2 main.c getline.c getline.h strcpy.c strcpy.h strreplace.c
        strreplace.h search_index.c search_index.h)

add_executable(lab test.c strreplacetest.c strreplacetest.h getlinetest.c getlinetest.h strreplace.h
        strreplace.c getline.h getline.c search_index.c search_index.h strcpy.c
        strcpy.h sstrcmp.c sstrcmp.h)