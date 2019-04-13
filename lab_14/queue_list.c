#include <stdlib.h>
#include "queue.h"

typedef struct node
{
    int element;
    struct node *next;
}node_t;

struct queue
{
    node_t *head;
    node_t *tail;
    int size;
};

void init_queue(queue_t **queue)
{
    queue_t *new_queue;
    new_queue = malloc(sizeof(queue_t));
    new_queue->tail = NULL;
    new_queue->head = new_queue->tail;
    new_queue->size = 0;
    *queue = new_queue;
}

void free_queue(queue_t *queue)
{
    while (queue->size != 0)
    {
        dequeue(queue);
    }
    free(queue);
}

int enqueue(queue_t *queue, int value)
{
    int flag = 0;
    if (queue->size == SIZE)
    {
        flag = SIZE;
    }

    if (queue->size == 0)
    {
        queue->tail = malloc(sizeof(node_t));
        queue->head = queue->tail;
    }
    else
    {
        queue->tail->next = malloc(sizeof(node_t));
        queue->tail = queue->tail->next;
    }
    queue->tail->element = value;
    queue->tail->next = NULL;
    (queue->size)++;

    return flag;
}

int dequeue(queue_t *queue)
{
    int value = 0;
    if (queue->size != 0)
    {
        value = queue->head->element;
        node_t *tmp = queue->head;
        queue->head = queue->head->next;
        free(tmp);
        (queue->size)--;
    }
    return value;
}

int empty_queue(queue_t *queue)
{
    return queue->size == 0;
}