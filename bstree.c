#include <stdlib.h>
#include "bstree.h"

struct TreeNode *create_node(int value) {
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node->value = value;

    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode *insert(struct TreeNode *node, int value) {
    if (node == NULL)
        return create_node(value);

    if (value < node->value) {
        node->left = insert(node->left, value);
        node->left->parent = node;
    } else {
        node->right = insert(node->right, value);
        node->right->parent = node;
    }

    return node;
}

void destroy_tree(struct TreeNode *root) {
    if (root == NULL) return;

    if (root->left != NULL) destroy_tree(root->left);
    if (root->right != NULL) destroy_tree(root->right);

    free(root);
}

struct TreeNode *minimum_node(struct TreeNode *root) {
    if (root == NULL || root->left == NULL) return root;

    return minimum_node(root->left);
}

struct TreeNode *maximum_node(struct TreeNode *node) {
    if (node == NULL || node->right == NULL) return node;

    return maximum_node(node->right);
}

struct TreeNode* find_node(struct TreeNode* root, int value) {
    if (root == NULL || root->value == value) return root;
    else if (value < root->value) return find_node(root->left, value);
    else return find_node(root->right, value);
}


bool contains(struct TreeNode *root, int value) {
    return find_node(root, value) != NULL;
}

struct TreeNode* remove_node(struct TreeNode* root, int value) {
    if (root == NULL) return NULL;

    if (root->value == value) return NULL;
}
