#include "queue.h"
#include <stdlib.h>

int enqueue(queue_t *queue, int data) {
    if(!queue) return 1;

    if(queue->size == 0) {
        queue->size++;
        queue->data = malloc(sizeof(int));
        queue->data[queue->size - 1] = data;
    } else {
        queue->size++;
        queue->data = realloc(queue->data, sizeof(int) * queue->size);
        queue->data[queue->size - 1] = data;
    }
    return 0;
}

int dequeue(queue_t *queue, int *data) {
    if(!queue) return 1;
    if(!data) return 2;

    if(queue->size == 0) return 3;

    *data = queue->data[0];
    for(size_t i = 0; i < queue->size; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->size--;
    queue->data = realloc(queue->data, sizeof(int) * queue->size);
    return 0;
}

int isEmpty(queue_t *queue) {
    if(!queue) return 2;

    if(queue->size > 0)
        return 1;
    else
        return 0;
}

int top(queue_t *queue, int *data) {
    if(!queue) return 1;
    if(!data) return 2;

    *data = queue->data[0];

    return 0;
}

int main(void) {
    return 0;
}
