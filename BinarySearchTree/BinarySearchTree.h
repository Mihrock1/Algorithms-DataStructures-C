#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int item;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

void print_in_order(Node *root);

void insert_node(Node **l, int data, Node *parent);

Node *search_node(Node *root, int data);

int delete_node(Node *root, int data);

int *capture_in_order(Node *root, int *size);

void free_tree(Node *root);

#endif
