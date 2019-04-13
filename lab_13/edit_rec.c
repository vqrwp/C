#include "edit_rec.h"

void edit_rec(lect_t **list, int index, int edit_ind, head_t **sort_arr, head_t **filter_arr, char *s, int num)
{
    if (list)
    {
        lect_t *cur = *list;
        int i = 0;

        for (; cur && i < index; cur = cur->next, i++);
        if (i == index)
        {
            del_from_sort_filter(cur);

            puts("here\n");
            switch (edit_ind)
            {
                case 1:
                    strcpy(cur->department, s);
                    break;
                case 2:
                    strcpy(cur->subject, s);
                    break;
                case 3:
                    strcpy(cur->lecturer, s);
                    break;
                case 4:
                    cur->age = num;
                    break;
            }

            add_berkli(cur, sort_arr, filter_arr);
            printf("The record number %d was edited\n", index + 1);
        }
        else
        {
            puts("There is no such index!\n");
        }
    }
    else
    {
        puts("Empty list!\n");
    }
}