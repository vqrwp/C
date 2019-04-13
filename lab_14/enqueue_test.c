#include "enqueue_test.h"

int enqueue_test()
{
    int flag = 0, value = 10;
    queue_t *q;
    init_queue(&q);
    if (q == NULL)
    {
        puts("Error in creating queue!\n");
        flag = 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        int res = enqueue(q, value);
        if (res != 0)
        {
            puts("Error while testing enqueue!\n");
            free_queue(q);
            flag = 1;
        }
    }
    int result = enqueue(q, value);
    free_queue(q);

    if (result != SIZE)
    {
        puts("Error while testing enqueue!\n");
        flag = 1;
    }
    return flag;
}