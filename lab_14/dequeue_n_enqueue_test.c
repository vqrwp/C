#include "dequeue_n_enqueue_test.h"

int dequeue_n_enqueue_test()
{
    int flag = 0, pushed = 10, popped = 0, result_push = 0;
    queue_t *q;
    init_queue(&q);
    if (q == NULL)
    {
        puts("Error in creating queue!\n");
        flag = 1;
    }

    result_push = enqueue(q, pushed);
    popped = dequeue(q);
    free_queue(q);

    if (result_push != 0 || pushed != popped)
    {
        puts("Error while testing enqueue and dequeue together!\n");
        flag = 1;
    }
    return flag;
}
