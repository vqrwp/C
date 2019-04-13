#include "del_rec.h"

void del_from_sort_filter(lect_t *p)
{
    for (int j = 0, k = 0; j < MAX_FILTER_INDX, k < MAX_SORT_INDX; j++, k++)
    {
        if (p->filter[j].next)
        {
            list_del(&p->filter[j]);
        }
        list_del(&p->sort[k]);
    }
}

int del_rec(lect_t **list, int index)
{
    int flag = 0;
    if (list)
    {
        lect_t *cur = *list, *prev = NULL;
        int i = 0;

        for (; cur && i < index; cur = cur->next, i++)
        {
            prev = cur;
        }
        if (i == index)
        {
            del_from_sort_filter(cur);
            if (prev)
            {
                prev->next = cur->next;
            }
            else
            {
                *list = cur->next;
            }
            free(cur);
        }
        else
        {
            flag = 1;
        }
    }
    else
    {
        flag = 1;
    }
    return flag;
}