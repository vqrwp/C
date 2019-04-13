#ifndef LAB_14_QUEUES_H
#define LAB_14_QUEUES_H

#define SIZE 10

typedef struct queue queue_t;

void init_queue(queue_t **queue);
void free_queue(queue_t *queue);
int enqueue(queue_t *queue, int value);
int dequeue(queue_t *queue);
int empty_queue(queue_t *queue);

#endif //LAB_14_QUEUES_H
