#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

void test_bst() {
    Node *root = NULL;

    // Test Insert
    insert_node(&root, 10, NULL);
    insert_node(&root, 5, NULL);
    insert_node(&root, 15, NULL);
    insert_node(&root, 3, NULL);
    insert_node(&root, 7, NULL);
    insert_node(&root, 12, NULL);
    insert_node(&root, 18, NULL);

    // Test Search
    assert(search_node(root, 10) != NULL); // root
    assert(search_node(root, 5) != NULL);  // left child
    assert(search_node(root, 15) != NULL); // right child
    assert(search_node(root, 3) != NULL);  // left-left child
    assert(search_node(root, 7) != NULL);  // left-right child
    assert(search_node(root, 12) != NULL); // right-left child
    assert(search_node(root, 18) != NULL); // right-right child
    assert(search_node(root, 100) == NULL); // non-existent

    // Test Capture In-Order
    int size;
    int *result = capture_in_order(root, &size);
    assert(size == 7);
    assert(result[0] == 3);
    assert(result[1] == 5);
    assert(result[2] == 7);
    assert(result[3] == 10);
    assert(result[4] == 12);
    assert(result[5] == 15);
    assert(result[6] == 18);
    free(result);

    // Test Delete
    assert(delete_node(root, 100) == 1); // Node not found
    assert(delete_node(root, 3) == 0);   // Delete leaf
    assert(search_node(root, 3) == NULL); // Should not be found
    assert(delete_node(root, 5) == 0);   // Delete node with one child
    assert(search_node(root, 5) == NULL); // Should not be found

    // Capture in-order after deletions
    result = capture_in_order(root, &size);
    assert(size == 5); // 10, 12, 15, 18
    assert(result[0] == 7);
    assert(result[1] == 10);
    assert(result[2] == 12);
    assert(result[3] == 15);
    assert(result[4] == 18);
    free(result);

    // Clean up
    free_tree(root);
}

// Main function with tests
int main() {
    test_bst();
    printf("All tests passed!\n");
    return 0;
}
