#pragma once

#include <stdbool.h>

struct TreeNode {
    int value;

    struct TreeNode* parent;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(int value);
struct TreeNode* insert(struct TreeNode* node, int value);
void destroy_tree(struct TreeNode* root);
struct TreeNode* minimum_node(struct TreeNode* node);
struct TreeNode* maximum_node(struct TreeNode* node);
bool contains(struct TreeNode* root, int value);
struct TreeNode* find_node(struct TreeNode* root, int value);
struct TreeNode* remove_node(struct TreeNode* root, int value);
