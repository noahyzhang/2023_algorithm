#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 1. 如果这个节点存在右子树，那么他的右子树上的最左节点即为后继节点
// 2. 如果这个节点没有右子树。此时当前节点记为 n，往上找，他的父节点记为 f。
//    （1）节点 n 是 f 的左子节点的话，f 就是 n 的后继节点。
//    （2）节点 n 是 f 的右子节点的话，需要继续往上找，直到找到一个节点 s，节点 s 是他父节点的左子节点。那么 s 的父节点就是 n 的后继节点
//    如果一直找，直到为 null，说明这个节点没有后继节点

TreeNode* get_next_node(TreeNode* node) {
    if (node == nullptr) return nullptr;
    if (node->right != nullptr) {
        node = node->right;
        for (; node->left != nullptr;) {
            node = node->left;
        }
        return node;
    }
    TreeNode* parent = node->parent;
    for (; parent != nullptr;) {
        if (parent->left == node) {
            return parent;
        }
        node = parent;
        parent = parent->parent;
    }
    return nullptr;
}