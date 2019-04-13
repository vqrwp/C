#include "dequeue_test.h"

int dequeue_test()
{
    int flag = 0;
    queue_t *q;
    init_queue(&q);
    if (q == NULL)
    {
        puts("Error in creating queue!\n");
        flag = 1;
    }

    dequeue(q);
    free_queue(q);

    if (!empty_queue(q))
    {
        puts("Error in testing dequeue on empty queue!\n");
        flag = 1;
    }
    return flag;
}