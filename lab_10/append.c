#include "append.h"
#include "struct.h"
#include "push.h"
#include "popfront.h"
#include "list_funcs.h"
#include "popend.h"
#include <stdio.h>

/*
Добавляет второй список в конец первого, очищает второй список

@param head_a [in] - первый список
@param head_b [in] - второй список

@return ничего не возвращает
*/
void append(node_t **head_a, node_t **head_b)
{
    node_t *tmp = *head_b;
    while (tmp->next)
    {
        void *x = pop_front(&tmp);
        push(head_a, x);
    }
    void *x = pop_back(&tmp);
    push(head_a, x);
    *head_b = NULL;
}
