#include <stdio.h>
#include "bst.h"

int main() {
    // Insertion test
    printf("Starting Insertion Test on BST...\n");
    Node *root = NULL;
    int value;

    // Accepting input from the user
    printf("Enter integers to insert into the BST (enter -1 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);

        if (value == -1) { // Exit condition
            break;
        }

        // Insert the value into the BST
        insert_node(&root, value, NULL);
    }

    // Print the BST in order
    printf("BST In-Order Traversal: ");
    print_in_order(root);
    printf("\n");


    // Search test
    printf("Starting Search Test on BST...\n");
    int search_item;
    printf("Enter the value to search for in the tree: ");
    scanf("%d", &search_item);
    printf("\n");
    const Node *node = search_node(root, search_item);

    if(node == NULL) {
        printf("%d not found in tree", search_item);
    }
    else {
        printf("Found %d", node->item);

        if (node->parent != NULL) {
            printf(" as child of %d", node->parent->item);
        } else {
            printf(" as root (no parent)");
        }

        if (node->left != NULL) {
            printf(" and as parent of left child %d", node->left->item);
        } else {
            printf(" and has no left child");
        }

        if (node->right != NULL) {
            printf(" and as parent of right child %d", node->right->item);
        } else {
            printf(" and has no right child");
        }

        printf("\n");
    }
}
