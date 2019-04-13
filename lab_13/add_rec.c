#include "add_rec.h"

void add_rec(lect_t **list, head_t **sort_arr, head_t **filter_arr,
    char *dep, char *subj, char *lect, int age)
{
    lect_t *new_elem = malloc(sizeof(lect_t));
    new_elem->next = NULL;

    strcpy(new_elem->department, dep);

    strcpy(new_elem->lecturer, lect);

    strcpy(new_elem->subject, subj);

    new_elem->age = age;

    *list = push_node(*list, new_elem);
    add_berkli(new_elem, sort_arr, filter_arr);

}