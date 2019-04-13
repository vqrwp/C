cmake_minimum_required(VERSION 3.10)
project(lab_13 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_13 main.c list.h menu.c menu.h scan_int.c scan_int.h read_file.c read_file.h
        push_node.c push_node.h show.c show.h add_rec.c add_rec.h comparator.c comparator.h berkli.c
        berkli.h del_rec.c del_rec.h edit_rec.c edit_rec.h sort.c sort.h filter.c filter.h save_in_file.c
        save_in_file.h)

add_executable(lab_13_test test.c list.h menu.c menu.h scan_int.c scan_int.h read_file.c read_file.h
        push_node.c push_node.h show.c show.h add_rec.c add_rec.h comparator.c comparator.h berkli.c
        berkli.h del_rec.c del_rec.h edit_rec.c edit_rec.h sort.c sort.h filter.c filter.h save_in_file.c
        save_in_file.h test1.c test1.h test2.c test2.h test3.c test3.h)