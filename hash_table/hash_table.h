#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_
#include <stddef.h>

typedef struct {
    const char *name;
    int data;
} data_t;

typedef struct {
    data_t *data;
    size_t capacity;
    size_t size;
} hash_table_t;

size_t get_hash(const char *name);

int table_insert(hash_table_t *hash_table, const char *name, int value);

int table_delete(hash_table_h *hash_table, const char *name);

void table_init(hash_table_t *hash_table);

void table_free(hash_table_t *hash_table);
#endif