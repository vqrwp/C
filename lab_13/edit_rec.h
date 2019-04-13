#ifndef LAB_13_EDIT_REC_H
#define LAB_13_EDIT_REC_H

#include "list.h"
#include <stdlib.h>
#include "del_rec.h"
#include "read_file.h"

void edit_rec(lect_t **list, int index, int edit_ind, head_t **sort_arr, head_t **filter_arr,
    char *s, int num);

#endif //LAB_13_EDIT_REC_H
