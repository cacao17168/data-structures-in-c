#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

vertex_t *find_vertex(graph_t *graph, int id) {
    for(size_t i = 0; i < graph->vertex_count; i++) {
        if(graph->vertex[i].id == id)
            return &graph->vertex[i];
    }
    return NULL;
}

int isExist_vertex(graph_t *graph, int id) {
    for(size_t i = 0; i < graph->vertex_count; i++) {
        if(graph->vertex[i].id == id) {
            return 1;
        }
    }
    return 0;
}

int find_vertex_index(graph_t *graph, int id) {
    for(size_t i = 0; i < graph->vertex_count; i++) {
        if(graph->vertex[i].id == id) {
            return (int)i;
        }
    }
    return -1;
}

int has_edge(vertex_t *v, int target_id) {
    if(!v->edge) return 0;
    {
            return 2;
        }
    for(size_t i = 0; v->edge[i] != NULL; i++) {
        if(v->edge[i]->target_vertex_id == target_id) {
            return 1;
        }
    }
    return 0;
}

int append_edge(vertex_t *v, edge_t *e) {
    if(!v || !e) return 1;

    size_t n = 0;

    if(v->edge) {
        while(v->edge != NULL) {
            n++;
        }
    }

    edge_t **new_edges = realloc(v->edge, sizeof(edge_t *) * (n + 2));
    if(!new_edges) return 2;

    v->edge = new_edges;
    v->edge[n] = e;
    v->edge[n + 1] = NULL;
    return 0;
}

void free_edges(vertex_t *v) {
    if(!v->edge) return;

    for(size_t i = 0; v->edge[i] != NULL; i++) {
        free(v->edge[i]);
    }

    free(v->edge);
    v->edge = NULL;
}

int remove_edge_to(vertex_t *v, int target_id) {
    if(!v->edge) return 0;

    for(size_t i = 0; v->edge[i] != NULL; i++) {
        if(v->edge[i]->target_vertex_id == target_id) {
            free(v->edge[i]);

            for(size_t j = i; v->edge[j] != NULL; j++) {
                v->edge[j] = v->edge[j + 1];
            }

            return 1;
        }
    }

    return 0;
}

void graph_init(graph_t *graph) {
    graph->vertex = NULL;
    graph->vertex_capacity = 0;
    graph->vertex_count = 0;
}

void graph_free(graph_t *graph) {
    if(!graph) return;

    for(size_t i = 0; i < graph->vertex_count; i++) {
        free_edges(&graph->vertex[i]);
    }
    free(graph->vertex);

    graph->vertex = NULL;
    graph->vertex_capacity = 0;
    graph->vertex_count = 0;
}

int add_vertex(graph_t *graph, int id) {
    if(!graph) return 1;
    if(isExist_vertex(graph, id) == 1) return 2;

    if(graph->vertex_count == graph->vertex_capacity) {
        int new_capacity = graph->vertex_capacity == 0
                            ? 4
                            : graph->vertex_capacity * 2;
        vertex_t *tmp = realloc(graph->vertex, sizeof(vertex_t) * new_capacity);
        if(!tmp) return 3;
        graph->vertex = tmp;
        graph->vertex_capacity = new_capacity;
    }

    vertex_t *v = &graph->vertex[graph->vertex_count++];
    if(!v) return 4;

    v->id = id;
    v->edge = NULL;
    return 0;
}

int remove_vertex(graph_t *graph, int id) {
    if(!graph) return 1;
    if(isExist_vertex(graph, id) == 0) return 2;

    int idx = find_vertex_index(graph, id);
    if(idx == -1) return 3;

    vertex_t *v = &graph->vertex[idx];

    for(size_t i = 0; v->edge != NULL ; i++) {
        free(v->edge[i]);
    }
    free(v->edge);
    v->edge = NULL;

    for(size_t i = 0; i < graph->vertex_count; i++) {
        if((int)i == idx) {
            continue;
        }
        v = &graph->vertex[i];
        free(v->edge[i]);

        for(size_t j = i; v->edge[j] != NULL; ++j) {
            v->edge[j] = v->edge[j + 1];
        }
    }

    for(size_t i = (size_t)idx; i + 1 < graph->vertex_count; ++i) {
        graph->vertex[i] = graph->vertex[i + 1];
    }

    graph->vertex_count--;

    return 0;
}

int add_edge(graph_t *graph, int from, int to) {
    if(!graph) return 1;

    vertex_t *from_v = find_vertex(graph, from);
    vertex_t *to_v = find_vertex(graph, to);

    if(!from_v || !to_v) return 2;

    if(has_edge(to_v, to)) return 3;

    edge_t *e = malloc(sizeof(edge_t));
    if(!e) return 4;

    e->target_vertex_id = to;
    if(append_edge(from_v, e) != 0) {
        free(e);
        return 5;
    }

    return 0;
}

int remove_edge(graph_t *graph, int from, int to) {
    vertex_t *from_v = find_vertex(graph, from);
    vertex_t *to_v = find_vertex(graph, to);

    if(!from_v || !to_v) return 1;

    if(remove_edge_to(from_v, to)) return 0;

    return 2;
}

int main() {
    return 0;
}
