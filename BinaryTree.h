#pragma once

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int val);
    void inorder();

private:
    TreeNode* root;
    void insert(TreeNode*& node, int val);
    void inorder(TreeNode* node);
    void destroy(TreeNode* node);
};
