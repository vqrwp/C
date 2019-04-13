#ifndef LAB_13_MENU_H
#define LAB_13_MENU_H

#include <stdio.h>
#include "list.h"
#include "scan_int.h"
#include "read_file.h"
#include "add_rec.h"
#include "del_rec.h"
#include "edit_rec.h"
#include "sort.h"
#include "filter.h"
#include "save_in_file.h"

int menu(FILE *f, FILE *fo);
void deleting(lect_t *list);
void edition(lect_t *list, head_t **sort_arr, head_t **filter_arr);
void addition(lect_t *list, head_t **sort_arr, head_t **filter_arr);
void print_menu();

#endif //LAB_13_MENU_H
