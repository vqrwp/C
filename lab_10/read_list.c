#include "read_list.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "push.h"
#include "list_funcs.h"
#include <malloc.h>

/*
Читает целочисленный список из файла

@param list [in] - список
@param f [in] - имя файла
@param list [out] - список

@return ничего не возвращает
*/
node_t* read_list_int(node_t **list, FILE *f)
{
    rewind(f);
    int i = 0;
    values_i *new = NULL;
    while (!feof(f))
    {
        int x = 0;
        fscanf(f, "%d", &x);
        push_v(&new, x);
        push(list, &(new->data));
        i++;
    }
    return *list;
}

/*
Читает символьный список из файла

@param list [in] - список
@param f [in] - имя файла
@param list [out] - список

@return ничего не возвращает
*/
node_t* read_list_char(node_t **list, FILE *f)
{
    rewind(f);
    int i = 0;
    values_i *new = NULL;
    while (!feof(f))
    {
        char x = 0;
        fscanf(f, "%c", &x);
        push_v(&new, x);
        push(list, &(new->data));
        i++;
    }
    return *list;
}
