#ifndef LAB_13_READ_FILE_H
#define LAB_13_READ_FILE_H

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_node.h"
#include "show.h"
#include "berkli.h"

void fill_num(int *num, char *string, int fl);
void fill_str(char *pString, char *string);
void add_berkli(lect_t *new_elem, head_t **sort_arr, head_t **filter_arr);
lect_t *read_file(FILE *f, lect_t *list, head_t **sort_arr, head_t **filter_arr);

#endif //LAB_13_READ_FILE_H
