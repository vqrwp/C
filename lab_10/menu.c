#include "menu.h"
#include "struct.h"
#include <stdio.h>
#include "read_list.h"
#include "list_funcs.h"
#include "popend.h"
#include "popfront.h"
#include "append.h"
#include "insert_sort.h"
#include <malloc.h>
#include <string.h>

/*
Меню программы, здесь происходит выбор того, какое действие предстоит сделать, передаются
 данные в функцию.

@param argv1 [in] - код операции
@param argv3 [in] - имя третьего файла
@param fi [in] - отсюда считывается список
@param fo [in] - сюда записывается результат

@return ничего не возвращает
*/
void menu(char *argv1, char *argv3, FILE *fi, FILE *fo)
{
    node_t *list = NULL;
    list = read_list_int(&list, fi);
    if (strcmp(argv1, "pb") == 0)
    {
        int *y = pop_back(&list);
        fprintf(fo, "\npop = %d\n", *y);
    }
    if (strcmp(argv1, "pf") == 0)
    {
        int *x = pop_front(&list);
        fprintf(fo, "\npop = %d\n", *x);
    }
    if (strcmp(argv1, "ap") == 0)
    {
        FILE *f2 = fopen(argv3, "r+");
        if (f2)
        {
            node_t *list2 = NULL;
            read_list_int(&list2, f2);

            append(&list, &list2);
            fprint_from_head(list, 0, fo);
        }
        else
        {
            fprintf(fo, "Error in opening file!\n");
        }
        fclose(f2);
    }
    if (strcmp(argv1, "is") == 0)
    {
        node_t *new_root = NULL;
        if (list->next != NULL)
        {
            new_root = sort(list, comparator_int);
            fprint_from_head(new_root, 0, fo);
        }
        else
        {
            fprint_from_head(list, 0, fo);
        }
    }
    if (strcmp(argv1, "st") == 0)
    {
        /*
        Даны два списка годов постройки домов, слить их в один и отсортировать по возрастанию.
        */
        FILE *f2 = fopen(argv3, "r+");
        if (f2)
        {
            node_t *list2 = NULL;
            read_list_int(&list2, f2);
            append(&list, &list2);
            node_t *new_root = NULL;
            new_root = sort(list, comparator_int);
            fprint_from_head(new_root, 0, fo);
        }
        fclose(f2);
    }
}
