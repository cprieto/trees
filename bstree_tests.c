#define CLOVE_SUITE_NAME BSTree
#include "bstree.h"
#include "clove-unit.h"

CLOVE_TEST(CreateNode) {
    struct TreeNode* root = create_node(5);

    CLOVE_NOT_NULL(root);
    CLOVE_INT_EQ(root->value, 5);

    destroy_tree(root);
}

CLOVE_TEST(InsertLeftValues) {
    struct TreeNode* root = create_node(5);
    insert(root, 2);

    CLOVE_NOT_NULL(root);
    CLOVE_INT_EQ(root->value, 5);

    CLOVE_NOT_NULL(root->left);
    CLOVE_INT_EQ(root->left->value, 2);

    CLOVE_NULL(root->right);

    destroy_tree(root);
}

CLOVE_TEST(InsertRightValues) {
    struct TreeNode* root = create_node(5);
    insert(root, 8);

    CLOVE_NOT_NULL(root);
    CLOVE_INT_EQ(root->value, 5);

    CLOVE_NOT_NULL(root->right);
    CLOVE_INT_EQ(root->right->value, 8);

    CLOVE_NULL(root->left);

    destroy_tree(root);
}

CLOVE_TEST(InsertRandomValues) {
    struct TreeNode* root = create_node(5);

    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // [5 [3 [2 [] 4 []] 7 [6 [] 8 []]]]
    CLOVE_NOT_NULL(root->left);
    CLOVE_INT_EQ(3, root->left->value);

    CLOVE_NOT_NULL(root->left->left);
    CLOVE_INT_EQ(2, root->left->left->value);
    CLOVE_NULL(root->left->left->left);

    CLOVE_NOT_NULL(root->left->right);
    CLOVE_INT_EQ(4, root->left->right->value);

    destroy_tree(root);
}

CLOVE_TEST(Minimum) {
    struct TreeNode* root = create_node(5);

    struct TreeNode* min = minimum_node(root);
    CLOVE_NOT_NULL(min);
    CLOVE_INT_EQ(5, min->value);

    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    min = minimum_node(root);
    CLOVE_NOT_NULL(min);
    CLOVE_INT_EQ(2, min->value);

    destroy_tree(root);
}

CLOVE_TEST(Maximum) {
    struct TreeNode* root = create_node(5);

    struct TreeNode* max = maximum_node(root);
    CLOVE_NOT_NULL(max);
    CLOVE_INT_EQ(5, max->value);

    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    max = maximum_node(root);
    CLOVE_NOT_NULL(max);
    CLOVE_INT_EQ(8, max->value);

    destroy_tree(root);
}

CLOVE_TEST(Contains) {
    struct TreeNode* root = create_node(5);

    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    CLOVE_IS_TRUE(contains(root, 4));
    CLOVE_IS_FALSE(contains(root, 12));

    destroy_tree(root);
}

CLOVE_TEST(FindNode) {
    struct TreeNode* root = create_node(5);

    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    struct TreeNode* node = find_node(root, 2);
    CLOVE_NOT_NULL(node);
    CLOVE_INT_EQ(node->value, 2);
}

CLOVE_TEST(RemoveLeaf) {
    struct TreeNode* root = create_node(5);

    root = remove_node(root, 5);

    CLOVE_NULL(root);
}
