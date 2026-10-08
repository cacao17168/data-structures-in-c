#include "hash_table.h"
#include <stdlib.h>
#include <string.h>

size_t get_hash(const char *name) {
    size_t h = 5381;
    int c;

    while ((c = (unsigned char)*name++)) {
        h = ((h << 5) + h) + c;  // h * 33 + c
    }

    return h;
}

int rehash(hash_table_t *t, size_t new_cap) {
    if(!t) return 1;

    bucket_t **new_buckets = calloc(new_cap, sizeof(bucket_t *));
    if(!new_buckets) return 2;

    for(size_t i = 0; i < t->hcap; i++) {
        bucket_t *e = t->bucket[i];
        while(e) {
            bucket_t *next = e->next;
            size_t idx = get_hash(e->key) % new_cap;
            e->next = new_buckets[idx];
            new_buckets[idx] = e;
            e = next;
        }
    }

    free(t->bucket);
    t->bucket = new_buckets;
    t->hcap = new_cap;
    return 0;
}

void table_init(hash_table_t *hash_table) {
    if(!hash_table) return;

    hash_table->bucket = NULL;
    hash_table->hcap = 0;
    hash_table->hsiz = 0;
}

int table_insert(hash_table_t *hash_table, char *key, int value) {
    if(!hash_table || !key) return 1;
    size_t *cap = &hash_table->hcap;
    size_t *siz = &hash_table->hsiz;

    if(*cap == 0) {
        *cap = 4;
        bucket_t **tmp = calloc(*cap, sizeof(bucket_t *) * *cap);
        if(!tmp) return 2;
        hash_table->bucket = tmp;
    }
    size_t idx = get_hash(key) % *cap;
    size_t d = *siz / *cap;
    if(d > 0.75) {
        rehash(hash_table, hash_table->hcap * 2);
    }

    if(hash_table->bucket[idx] != NULL) {
        bucket_t *n = hash_table->bucket[idx]->next;
        while(n->next != NULL) {
            n = n->next;
        }
        bucket_t *new = n->next;
        new = malloc(sizeof(bucket_t));
        new->key = key;
        new->data = value;
        new->next = NULL;
    } else {
        bucket_t *n = hash_table->bucket[idx];
        n->key = key;
        n->data = value;
        n->next = NULL;
    }
    return 0;
}

int table_delete(hash_table_t *hash_table, char *key) {
    if(!hash_table || !key) return 1;
    size_t *cap = &hash_table->hcap;

    size_t idx = get_hash(key) % *cap;
    bucket_t *cur = hash_table->bucket[idx];
    if(!cur) return 2;

    if(strcmp(cur->key, key)) {
        while(strcmp(key, cur->next->key)) {
            cur = cur->next;
        }
        bucket_t *for_del = cur->next;
        cur->next = for_del->next;
        free(for_del);
    } else {
        free(cur);
    }

    hash_table->hsiz--;
    return 0;
}

void table_free(hash_table_t *hash_table) {
    if (hash_table == NULL) {
        return;
    }

    if (hash_table->bucket != NULL) {
        for (size_t i = 0; i < hash_table->hcap; i++) {
            bucket_t *current = hash_table->bucket[i];

            while (current != NULL) {
                bucket_t *tmp = current;
                current = current->next;

                free(tmp);
            }
        }
        free(hash_table->bucket);
        hash_table->bucket = NULL;
    }

    hash_table->hcap = 0;
    hash_table->hsiz = 0;
}

int main(void) {
    return 0;
}
