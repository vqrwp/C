#include "sort.h"

void print_sort(head_t **sort_arr, int sort_type)
{
    head_t *list;
    lect_t *p = NULL;
    puts("# |Department|  Subject  |Age|    Lecturer   |\n");
    puts("---------------------------------------------\n");
    int i = 1;
    list_for_each(list, sort_arr[sort_type])
    {
        p = list_entry(list, lect_t, sort[sort_type]);
        printf("%2d|%10s|%11s|%3d|%15s|\n", i++, p->department, p->subject,
               p->age, p->lecturer);
    }
    puts("---------------------------------------------\n");
    if (!p)
    {
        printf("The list is empty\n");
    }
}