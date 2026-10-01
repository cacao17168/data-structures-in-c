#ifndef QUEUE_H_
#define QUEUE_H_
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
} queue_t;

int enqueue(queue_t *queue, int data);

int dequeue(queue_t *queue, int *data);

int isEmpty(queue_t *queue);

int top(queue_t *queue, int *data);

#endif
