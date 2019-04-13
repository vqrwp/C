#include <stdio.h>
#include "queue.h"
#include "dequeue_test.h"
#include "enqueue_test.h"
#include "dequeue_n_enqueue_test.h"

int main()
{
    if (!dequeue_test() && !dequeue_n_enqueue_test() && !enqueue_test())
    {
        printf("Tests approved!\n");
    }
    else
    {
        puts("Tests failed!\n");
    }
    return 0;
}
