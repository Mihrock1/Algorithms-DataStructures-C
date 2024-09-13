#include "bst.h"
#include <stdio.h>

int delete_node(Node *root, const int data) {
  Node *node = search_node(root, data);

  if(node == NULL) {
    return 1;
  }

  if(node->left == NULL && node->right == NULL) {
    if(node->parent->left == node) {
      node->parent->left = NULL;
    }
    else if(node->parent->right == node) {
      node->parent->right = NULL;
    }
  }
  else if(node->left != NULL && node->right == NULL) {
    if(node->parent->left == node) {
      node->parent->left = node->left;
    }
    else if(node->parent->right == node) {
      node->parent->right = node->left;
    }
  }
  else if(node->right != NULL && node->left == NULL) {
    if(node->parent->left == node) {
      node->parent->left = node->right;
    }
    else if(node->parent->right == node) {
      node->parent->right = node->right;
    }
  }
  else {
    Node *child = node->right;

    while(child->left != NULL) {
      child = child->left;
    }

    node->item = child->item;

    if(node->right == child) {
      node->right = child->right;
    }
    else {
      child->parent->left = NULL;
    }
  }

  return 0;
}