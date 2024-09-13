#include "bst.h"
#include <stdio.h>

Node *search_node(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->item == data) {
        return root;
    }
    else if (root->item > data) {
        return search_node(root->left, data);
    }
    else {
        return search_node(root->right, data);
    }
}
