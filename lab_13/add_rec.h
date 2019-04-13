#ifndef LAB_13_ADD_REC_H
#define LAB_13_ADD_REC_H

#include "list.h"
#include <stdlib.h>
#include "read_file.h"
#include "scan_int.h"

void add_rec(lect_t **list, head_t **sort_arr, head_t **filter_arr,
             char *dep, char *subj, char *lect, int age);

#endif //LAB_13_ADD_REC_H
