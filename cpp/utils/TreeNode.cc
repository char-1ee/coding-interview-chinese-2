#include "TreeNode.h"
#include <cstdio>
#include <iostream>

void PrintTreeHelper(const TreeNode* root, std::string prefix, bool is_left);

void DestroyTree(TreeNode* root) {
    if (root == nullptr) return;

    TreeNode* left_tree = root->left;
    TreeNode* right_tree = root->right;

    delete root;
    root = 0; // NULL for windows, 0 for cross-platform

    DestroyTree(left_tree);
    DestroyTree(right_tree);

    // Another way:
    // DestroyTree(root->left);
    // DestroyTree(root->right);
    // delete root;
}

void PrintTree(const TreeNode* root) {
    std::string prefix = "";
    bool is_left = true;

    PrintTreeHelper(root, prefix, is_left);
}

void PrintTreeHelper(const TreeNode* root, std::string prefix, bool is_left) {
    if (root == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    }

    if (root->right != nullptr) {
        std::string new_prefix = prefix + (is_left ? "    " : "   |");
        PrintTreeHelper(root->right, new_prefix, true);
    }

    std::cout << prefix + (is_left ? "└── " : "┌── ") + std::to_string(root->val) + "\n";

    if (root->left != nullptr) {
        std::string new_prefix = prefix + (is_left ? "|   " : "    ");
        PrintTreeHelper(root->left, new_prefix, false);
    }
}

Node* CreateTreeNode(int val) {
    Node* node = new Node();
    node->val = val;
    return node;
}

void ConnectTreeNodes(Node* root, Node* child) {
    if (root) root->children.push_back(child);
}