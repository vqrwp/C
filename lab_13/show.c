#include "show.h"

void show(lect_t *list)
{
    lect_t *p = list;
    printf("# |Department|  Subject  |Age|    Lecturer   |\n");
    printf("---------------------------------------------------------"
           "---------------------------------------------------------\n");
    for (int i = 0; p; i++, p = p->next)
    {
        printf("%2d|%10s|%11s|%3d|%15s|\n", i + 1, p->department, p->subject, p->age, p->lecturer);
    }
    printf("------------------------------------------------------------"
           "------------------------------------------------------------");
}