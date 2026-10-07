#include "binary_tree.h"
#include <stdlib.h>

Node* min_value(Node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *create_node(int value) {
    Node *n = malloc(sizeof(Node));
    if(!n) return NULL;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int value) {
    if(root == NULL) return create_node(value);
    if(value < root->data) {
	root->left = insert(root->left, value);
    } else if(value > root->data) {
	root->right = insert(root->right, value);
    }
    return root;
}

Node *search(Node *root, int value) {
    if(root == NULL || root->data == value)
	return root;
    if(value < root->data)
	return search(root->left, value);
    return search(root->right, value);
}

Node *delete_node(Node *root, int value) {
    if(root == NULL) return NULL;
    if(value < root->data) {
	root->left = delete_node(root->left, value);
    } else if(value > root->data) {
	root->right = delete_node(root->right, value);
    } else {
	if(root->left == NULL) {
	    Node* tmp = root->right;
	    free(root);
	    return tmp;
	}
	if(root->right == NULL) {
	    Node *tmp = root->left;
	    free(root);
	    return tmp;
	}
	
	Node *tmp = min_value(root->right);
	root->data = tmp->data;
	root->right = delete_node(root->right, tmp->data);
    }
    return root;
}

void free_tree(Node *root) {
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    return 0;
}