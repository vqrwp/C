//
// Created by Margo on 16.12.2018.
//

#include "push_node.h"

void push_t(t_city **list, t_city *node)
{
    node->next = *list;
    *list = node;
}