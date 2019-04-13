//
// Created by Margo on 17.12.2018.
//

#include "free.h"
#include "struct.h"
#include "delete_node.h"

t_stud* frees(t_stud *list)
{
    t_stud *curr = list->next;

    while (curr)
    {
        t_stud *tmp = curr;
        curr = curr->next;
        free(tmp->name);
        tmp->list_marks = frees(tmp->list_marks);
        free(tmp);
    }
    free(list->name);
    list->next = NULL;
    return list;
}

t_marks* frees(t_stud *list)
{
    t_stud *curr = list->next;

    while (curr)
    {
        t_stud *tmp = curr;
        curr = curr->next;
        free(tmp->name);
        tmp->list_marks = frees(tmp->list_marks);
        free(tmp);
    }
    free(list->name);
    list->next = NULL;
    return list;
}