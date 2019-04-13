//
// Created by Margo on 16.12.2018.
//

#ifndef RK_04_STRUCT_H
#define RK_04_STRUCT_H

#include <stdio.h>
#include <malloc.h>
#include "errors.h"
#include <string.h>
#include <stdlib.h>
#include "push_node.h"

typedef struct citys
{
    char name[300];
    char region[300];
    char district[300];
    int population;
    int year_of_foundation;
    struct citys *next;
}t_city;

int read_struct(t_city **list, FILE *f, FILE *fo);

#endif //RK_04_STRUCT_H
