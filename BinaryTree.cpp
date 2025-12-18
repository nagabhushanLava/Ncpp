#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::insert(int val) {
    insert(root, val);
}

void BinaryTree::insert(TreeNode*& node, int val) {
    if (!node) {
        node = new TreeNode(val);
        return;
    }
    if (val < node->value)
        insert(node->left, val);
    else
        insert(node->right, val);
}

void BinaryTree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BinaryTree::inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->value << " ";
    inorder(node->right);
}

void BinaryTree::destroy(TreeNode* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
