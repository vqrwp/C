#ifndef LAB_10_INSERT_SORT_H
#define LAB_10_INSERT_SORT_H

#include "struct.h"


node_t* sort(node_t *head, int (*comparator)(const void *, const void *));
int comparator_int(const void *p, const void *q);
void sorted_insert(node_t **head, node_t *element,
                   int (*comparator)(const void *, const void *));
int comparator_char(const void *p, const void *q);
int comparator_float(const void *p, const void *q);

#endif //LAB_10_INSERT_SORT_H
