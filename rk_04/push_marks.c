//
// Created by Margo on 17.12.2018.
//

#include "push_marks.h"
#include "struct.h"

void push_marks(t_marks **list, int elem)
{
    t_marks* node = malloc(sizeof(t_marks));
    node->mark = elem;
    node->next = *list;
    *list = node;
}
