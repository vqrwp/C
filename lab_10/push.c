#include "push.h"
#include <malloc.h>
#include <stdio.h>
#include "list_funcs.h"

/*
Добавляет элемент в список

@param list [in] - список
@param elem [in] - элемент, который нужно добавить

@return ничего не возвращает
*/
void push(node_t** list, void *elem)
{
    node_t* node = malloc(sizeof(node_t));
    node->data = elem;
    node->next = *list;
    *list = node;
}

/*
Добавляет элемент в список

@param list [in] - список
@param elem [in] - элемент, который нужно добавить

@return ничего не возвращает
*/
void push_v(values_i** list, int elem)
{
    values_i* node = malloc(sizeof(node_t));
    node->data = elem;
    node->next = *list;
    *list = node;
}

/*
Добавляет элемент в список

@param list [in] - список
@param elem [in] - элемент, который нужно добавить

@return ничего не возвращает
*/
void push_c(values_c** list, char elem)
{
    values_c* node = malloc(sizeof(node_t));
    node->data = elem;
    node->next = *list;
    *list = node;
}