cmake_minimum_required(VERSION 3.10)
project(rk C)

set(CMAKE_C_STANDARD 99)

add_executable(rk main.c counting_words_in_file.c counting_words_in_file.h print_struct.c print_struct.h)