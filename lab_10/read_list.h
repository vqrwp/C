#ifndef LAB_10_READ_LIST_H
#define LAB_10_READ_LIST_H

#include "struct.h"
#include <stdio.h>

node_t* read_list_int(node_t **list, FILE *f);
node_t* read_list_char(node_t **list, FILE *f);

#endif //LAB_10_READ_LIST_H
