#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>

typedef struct {
	int *data;
	size_t capacity; //the whole array size
	size_t size; //current busy indexes
} array_t; //array typedef

void array_init(array_t* arr); //initialize array; allocate memory for 1 element

int array_insert(array_t* arr, size_t index, int data); //insert int data to specified index; 0 on success

int array_get(array_t* arr, size_t index, int *data); //return int *data from specified index; 0 on success

int array_delete(array_t* arr, size_t index); //remove data from specified index and move following elements by 1; 0 on success

int array_size(array_t* arr, size_t *data); //return array size; 0 on success

int array_free(array_t* arr); //free all array memory; 0 on success

#endif
