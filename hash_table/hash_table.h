#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_
#include <stddef.h>

typedef struct bucket_t {
    char *key;
    int data;
    struct bucket_t *next;
} bucket_t;

typedef struct {
    bucket_t **bucket;
    size_t hcap;
    size_t hsiz;
} hash_table_t;

size_t get_hash(const char *name);

int table_insert(hash_table_t *hash_table, char *key, int value);

int table_delete(hash_table_t *hash_table, char *key);

void table_init(hash_table_t *hash_table);

void table_free(hash_table_t *hash_table);
#endif
