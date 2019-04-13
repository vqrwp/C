#include "print.h"
#include "struct.h"

void print_from_head(t_stud *list, int count)
{
    if (list)
    {
        print_from_head(list->next, ++count);
        printf("\n%s %d ", list->name, list->age);
        print_from_head_marks(list->list_marks, 0);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
    }
}

void print_from_head_marks(t_marks *list, int count)
{
    if (list)
    {
        print_from_head_marks(list->next, ++count);
        printf("%d ", list->mark);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
    }
}