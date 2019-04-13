#include "save_in_file.h"

void save_in_file(FILE *f, lect_t *list)
{
    rewind(f);
    lect_t *p = list;
    for (; p; p = p->next)
    {
        if (p->next != NULL)
        {
            fprintf(f, "%s; %s; %s; %d\n", p->department, p->lecturer, p->subject, p->age);
        }
        else
        {
            fprintf(f, "%s; %s; %s; %d", p->department, p->lecturer, p->subject, p->age);
        }
    }
}