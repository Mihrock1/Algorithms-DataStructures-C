//
// Created by Mihir Atrey on 2024-09-08.
//

#include <stdio.h>
#include <stdlib.h>
#include  "bst.h"

void insert_node(Node **l, const int data, Node *parent) {
    if(*l == NULL) {
        Node *p = malloc(sizeof(Node));
        p->item = data;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if(data < (*l)->item) {
        insert_node(&(*l)->left, data, *l);
    }
    else {
        insert_node(&(*l)->right, data, *l);
    }
}
