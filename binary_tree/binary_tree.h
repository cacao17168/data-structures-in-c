#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value);

Node *insert(Node *root, int value);

Node *search(Node *root, int value);

Node *delete_node(Node *root, int value);

void free_tree(Node *root);

#endif