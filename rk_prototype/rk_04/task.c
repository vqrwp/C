//
// Created by Margo on 16.12.2018.
//

#include "task.h"

void task(t_city *list, int count, int year, char *city)
{
    if (list)
    {
        if (list->year_of_foundation < year)
        {
            year = list->year_of_foundation;
            strcpy(city, list->name);
        }
        task(list->next, ++count, year, city);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
        else
        {
            printf("%s", city);
        }
    }
}