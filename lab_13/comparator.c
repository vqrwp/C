#include "comparator.h"

int comporator_depatment(lect_t *a, lect_t *b)
{
    return strcmp(a->department, b->department);
}

int comporator_age(lect_t *a, lect_t *b)
{
    return  a->age - b->age;
}