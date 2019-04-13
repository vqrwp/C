#include "push_node.h"

void push_t(t_stud **list, t_stud *node)
{
    node->next = *list;
    *list = node;
}