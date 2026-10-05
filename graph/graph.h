#ifndef GRAPH_H_
#define GRAPH_H_
#include <stddef.h>

typedef struct edge_t {
    int target_vertex_id;
} edge_t;

typedef struct {
    int id;
    edge_t **edge;
} vertex_t;

typedef struct {
    vertex_t *vertex;
    size_t vertex_count;
    size_t vertex_capacity;
} graph_t;

void graph_init(graph_t *graph);
void graph_free(graph_t *graph);

int add_vertex(graph_t *graph, int id);
int remove_vertex(graph_t *graph, int id);

int add_edge(graph_t *graph, int from, int to);
int remove_edge(graph_t *graph, int from, int to);

#endif
