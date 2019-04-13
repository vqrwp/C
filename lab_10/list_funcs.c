#include "list_funcs.h"
#include <stdio.h>

/*
Печатает список с головы

@param list [in] - список
@param count [in] - ключ пустоты

@return ничего не возвращает
*/
void print_from_head(const node_t *list, int count)
{
    if (list)
    {
        print_from_head(list->next, ++count);
        int *x = list->data;
        printf("%d ", *x);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
    }
}

/*
Печатает список в файл с головы

@param list [in] - список
@param count [in] - ключ пустоты
@param fo [in] - имя файла

@return ничего не возвращает
*/
void fprint_from_head(const node_t *list, int count, FILE *fo)
{
    if (list)
    {
        fprint_from_head(list->next, ++count, fo);
        int *x = list->data;
        fprintf(fo, "%d ", *x);
    }
    else
    {
        if (count == 0)
        {
            puts("\nEmpty structure!\n");
        }
    }
}
