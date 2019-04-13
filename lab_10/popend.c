#include "popend.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

/*
Вынимает значение из хвоста списка

@param list [in] - список
@param data [out] - значение из хвоста списка

@return значение из хвоста списка
*/
void* pop_back(node_t **list)
{
    node_t *temp = *list;
    void *data = temp->data;
    *list = temp->next;
    free(temp);
    return data;
}
