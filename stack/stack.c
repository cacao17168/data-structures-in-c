#include "stack.h"
#include <stdlib.h>

int push(lifo_t *lifo, int data) {
    if(!lifo) return 1;

    if(lifo->size == 0) {
        lifo->data = malloc(sizeof(int));
        lifo->size++;
        lifo->data[lifo->size - 1] = data;
    } else {
        lifo->size++;
        lifo->data = realloc(lifo->data, sizeof(int) * lifo->size);
        lifo->data[lifo->size - 1] = data;
    }
    return 0;
}

int pop(lifo_t *lifo, int *data) {
    if(!lifo) return 1;
    if(!data) return 2;

    if(lifo->size == 0) return 3;

    *data = lifo->data[lifo->size - 1];
    lifo->size--;
    lifo->data = realloc(lifo->data, sizeof(int) * lifo->size);

    return 0;
}

int isEmpty(lifo_t *lifo) {
    if(!lifo) return 2;

    if(lifo->size > 0)
        return 1;
    else
        return 0;
}

int top(lifo_t *lifo, int *data) {
    if(!lifo) return 1;
    if(!data) return 2;

    *data = lifo->data[lifo->size - 1];

    return 0;
}

int main(void) {
    return 0;
}
