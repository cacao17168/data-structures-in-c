#ifndef STACK_H_
#define STACK_H_
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
} lifo_t;

int push(lifo_t *lifo, int data);

int pop(lifo_t *lifo, int *data);

int isEmpty(lifo_t *lifo); //returns 0 on true and 1 on false; other codes interpret as error codes

int top(lifo_t *lifo, int *data);

#endif
