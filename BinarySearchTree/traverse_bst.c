#include "bst.h"
#include <stdio.h>

void print_in_order(Node *root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("%d ", root->item);
        print_in_order(root->right);
    }
}
