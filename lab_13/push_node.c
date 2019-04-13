#include "push_node.h"

lect_t *push_node(lect_t *list, lect_t *new_elem)
{
    if (list != NULL)
    {
        lect_t *p = list;
        for (; p->next; p = p->next);
        p->next = new_elem;
    }
    else
    {
        list = new_elem;
    }
    //show(list);
    return list;
}
