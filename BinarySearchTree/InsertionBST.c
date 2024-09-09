//
// Created by Mihir Atrey on 2024-09-08.
//

#include <stdlib.h>
#include <sys/_types/_null.h>

typedef struct Node {
    int item;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

void insert_tree(Node **l, const int data, Node *parent) {
    if(*l == NULL) {
        Node *p = malloc(sizeof(Node));
        p->item = data;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if(data < (*l)->item) {
        insert_tree(&(*l)->left, data, *l);
    }
    else {
        insert_tree(&(*l)->right, data, *l);
    }
}
