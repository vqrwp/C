//
// Created by Margo on 16.12.2018.
//

#include "print.h"
#include "struct.h"

void print_from_head(t_city *list, int count)
{
    if (list)
    {
        print_from_head(list->next, ++count);
        printf("%s %s %s %d %d\n", list->name, list->region, list->district,
               list->population, list->year_of_foundation);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
    }
}
