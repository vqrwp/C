#include <stdlib.h>
#include "queue.h"

struct queue
{
    int val[SIZE];
    int head;
    int tail;
};

void init_queue(queue_t **queue)
{
    queue_t *new_queue;
    new_queue = malloc(sizeof(queue_t));
    new_queue->head = 0;
    new_queue->tail = 0;
    *queue = new_queue;
}

void free_queue(queue_t *queue)
{
    free(queue);
}

int enqueue(queue_t *queue, int value)
{
    int flag = 0;
    if ((queue->tail - queue->head) == SIZE)
    {
        flag = SIZE;
    }
    else if (queue->tail == SIZE)
    {
        for (int i = queue->head; i < queue->tail; i++)
        {
            queue->val[i] = queue->val[i + queue->tail - queue->head];
        }
        if ((queue->tail - queue->head) == SIZE)
        {
            flag = SIZE;
        }
    }
    if (flag != SIZE)
    {
        queue->val[queue->tail] = value;
        queue->tail++;
    }
    return flag;
}

int dequeue(queue_t *queue)
{
    int value = 0;
    if (queue->tail != queue->head)
    {
        value = queue->val[queue->head];
        (queue->head)++;
        if (queue->tail != queue->head)
        {
            queue->head = 0;
            queue->tail = 0;
        }
    }
    return value;
}

int empty_queue(queue_t *queue)
{
    return queue->tail == queue->head;
}