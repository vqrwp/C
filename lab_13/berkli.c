#include "berkli.h"

int compare_strings(const lect_t *x, const lect_t *y)
{
    return strcmp(x->department, y->department);
}

int compare_ints(const lect_t *x, const lect_t *y)
{
    return x->age - y->age;
}

void add_to_sort(lect_t *list, head_t *head, int sort_type, int (*compar)(const lect_t*, const lect_t*))
{
    head_t *p, *new = &list->sort[sort_type];
    lect_t *cur = NULL;

    list_for_each(p, head)
    {
        cur = list_entry(p, lect_t, sort[sort_type]);
        int diff = 0;
        diff = compar(cur, list);
        if (diff > 0)
        {
            new->prev = p->prev;
            p->prev->next = new;
            new->next = p;
            p->prev = new;
            break;
        }
        else if (p->next == head)
        {
            list_add_tail(new, head);
            break;
        }
    }
    if (!cur)
        list_add_tail(new, head);
}