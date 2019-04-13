#ifndef RK_04_STRUCT_H
#define RK_04_STRUCT_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct marks
{
    int mark;
    struct marks *next;

}t_marks;

typedef struct Student
{
    char name[100];
    int age;
    t_marks *list_marks;
    struct Student *next;
}t_stud;

#endif //RK_04_STRUCT_H
