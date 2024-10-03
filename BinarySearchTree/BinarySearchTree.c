#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void insert_node(Node **l, const int data, Node *parent) {
    if (*l == NULL) {
        Node *p = malloc(sizeof(Node));
        p->item = data;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if (data < (*l)->item) {
        insert_node(&(*l)->left, data, *l);
    } else {
        insert_node(&(*l)->right, data, *l);
    }
}

void print_in_order(Node *root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("%d ", root->item);
        print_in_order(root->right);
    }
}

Node *search_node(Node *root, const int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->item == data) {
        return root;
    } else if (root->item > data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int delete_node(Node *root, const int data) {
    Node *node = search_node(root, data);

    if (node == NULL) {
        return 1; // Node not found
    }

    // Node is a leaf
    if (node->left == NULL && node->right == NULL) {
        if (node->parent->left == node) {
            node->parent->left = NULL;
        } else if (node->parent->right == node) {
            node->parent->right = NULL;
        }
    }
    // Node has one child
    else if (node->left != NULL && node->right == NULL) {
        if (node->parent->left == node) {
            node->parent->left = node->left;
        } else if (node->parent->right == node) {
            node->parent->right = node->left;
        }
    }
    else if (node->right != NULL && node->left == NULL) {
        if (node->parent->left == node) {
            node->parent->left = node->right;
        } else if (node->parent->right == node) {
            node->parent->right = node->right;
        }
    }
    // Node has two children
    else {
        const Node *child = node->right;

        while (child->left != NULL) {
            child = child->left;
        }
        node->item = child->item;

        // Remove the child node
        if (child->parent->right == child) {
            child->parent->right = NULL;
        } else {
            child->parent->left = NULL;
        }
        free((void *)child); // Free memory of the child node
    }

    free(node); // Free memory of the deleted node
    node = NULL; // Nullify the pointer

    return 0;
}

// Capture In-Order Traversal
int *capture_in_order(Node *root, int *size) {
    if (root == NULL) {
        *size = 0;
        return NULL;
    }

    int left_size = 0;
    int right_size = 0;

    // Capture left subtree
    int *left_array = capture_in_order(root->left, &left_size);
    // Capture right subtree
    int *right_array = capture_in_order(root->right, &right_size);

    // Allocate memory for the combined array
    *size = left_size + 1 + right_size;
    int *result = malloc(*size * sizeof(int));

    // Copy left subtree values
    for (int i = 0; i < left_size; i++) {
        result[i] = left_array[i];
    }

    // Add current node value
    result[left_size] = root->item;

    // Copy right subtree values
    for (int i = 0; i < right_size; i++) {
        result[left_size + 1 + i] = right_array[i];
    }

    // Free temporary arrays
    free(left_array);
    free(right_array);

    return result;
}

// Free the tree nodes
void free_tree(Node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
        root = NULL; // Nullify the pointer
    }
}