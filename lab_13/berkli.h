#ifndef LAB_13_BERKLI_H
#define LAB_13_BERKLI_H

#include "list.h"
#include <string.h>
#include <stdio.h>

int compare_strings(const lect_t *x, const lect_t *y);
int compare_ints(const lect_t *x, const lect_t *y);
void add_to_sort(lect_t *list, head_t *head, int sort_type, int (*compar)(const lect_t*, const lect_t*));

#endif //LAB_13_BERKLI_H
