#include <stdlib.h>

#include "../../include/data-structures/queue.h"


Queue createQueue(int size)
{
    Queue *q = malloc(sizeof(Queue));

    int *data = malloc(sizeof(size * sizeof(int)));

    q->data = data;
    q->size = size;
    q->length = 0;
    q->first = 0;

    return *q;
}


void freeQueue(Queue *q)
{
    // Free the pointer to the array
    // structure holding the data
    free(q->data);

    // Free the queue itself
    free(q);
}


int queue_dequeue(Queue *q)
{

}


void queue_enqueue(Queue *q, int value)
{
    // To enqueue '7'
    // 5 8 0 1
    // Index of first item  : 0 
    // Size of the queue    : 5
    // Length of the queue  : 4
}


int queue_get_length(Queue q)
{
    return q.length;
}


int queue_get_size(Queue q)
{
    return q.size;
}


int queue_is_empty(Queue q)
{
    return q.length == 0;
}


int queue_is_full(Queue q)
{
    return q.length == q.size;
}


