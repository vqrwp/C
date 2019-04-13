#include "popfront.h"
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "popend.h"

/*
Вынимает значение из головы списка

@param list [in] - список
@param data [out] - значение из головы списка

@return значение из головы списка
*/
void* pop_front(node_t **list)
{
    node_t *current = *list;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    void *data = current->next->data;
    current->next = NULL;
    return data;
}
