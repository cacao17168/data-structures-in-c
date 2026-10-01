#include "array.h"
#include <stdlib.h>

void array_init(array_t* arr) {
	if(!arr) return; //null check
	arr->capacity = 1; //initial capacity
	arr->size = 1;
	arr->data = malloc(sizeof(int)); //memory allocation for first element
	return;
}

int array_insert(array_t* arr, size_t index, int data) {
	if(!arr) return 1; //null check

	if(arr->size > index || arr->capacity + 1 < index) return 2; //check is index valid
	if(arr->size == arr->capacity) { //check array size and allocate memory if it's full
		arr->capacity++;
		int *temp = realloc(arr->data, arr->capacity * sizeof(int)); //allocate memory to temporary array
		if(temp) {
			arr->data = temp; //copy temporary array to constant
			arr->data[index] = data;
			arr->size++;
		}
		else return 3;
	} else { //if size is smaller than capacity
		arr->data[index] = data;
		arr->size++;
	}

	return 0;
}

int array_get(array_t* arr, size_t index, int *data) {
	if(!arr) return 1; //null check
	if(!data) return 2; //null check
	if(index > arr->capacity) return 3; //check if index is in array scopes

	*data = arr->data[index]; //write data to extern variable pointer

	return 0;
}

int array_delete(array_t* arr, size_t index) {
	if(!arr) return 1; //null check
	if(index > arr->capacity) return 2; //check if index is in array scopes

	arr->data[index] = 0; //0 means that element is deleted

	if(index < arr->capacity) { //check for ending element; if false all elements move by 1
		size_t i = index + 1;
		while(i <= arr->capacity) {
			arr->data[i - 1] = arr->data[i]; //moving element by 1 closer to first element
			i++;
		}
		arr->size--;
	}
	return 0;
}

int array_size(array_t* arr, size_t *data) {
	if(!arr) return 1; //null check
	if(!data) return 2; //null check

	*data = arr->size; //write data to extern variable pointer
	return 0;
}

int array_free(array_t* arr) {
	if(!arr) return 1;

	free(arr->data); //free up array memory
	arr->data = NULL; //apply null pointer to array
	arr->capacity = 0;
	arr->size = 0;

	return 0;
}

int main(void) {
    return 0;
}
