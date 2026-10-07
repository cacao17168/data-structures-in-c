#include "hash_table.c"
#include <stdlib.h>

void table_init(hash_table_t *hash_table) {
    if(!hash_table) return;
    hash_table->data = NULL;
    hash_table->capacity = 0;
    hash_table->size = 0;
}

void table_free(hash_table_t *hash_table) {
    if(!hash_table) return;
    for(size_t i = 0; i < hash_table->size; i++) {
	free(&hash_table->data[i]);
    }
    free(hash_table->data);
    hash_table->data = NULL;
    hash_table->capacity = 0;
    hash_table->size = 0;
}