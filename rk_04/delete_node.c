//
// Created by Margo on 17.12.2018.
//

#include "delete_node.h"
#include "struct.h"

void pop_back(t_stud **list)
{
    t_stud *temp = *list;
    *list = temp->next;
    free(temp);
}
