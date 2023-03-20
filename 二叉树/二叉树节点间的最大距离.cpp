#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int get_max_distance(TreeNode* root) {
        int node_distance = 0;
        return get_max_distance_internal(root, &node_distance);
    }

private:
    int get_max_distance_internal(TreeNode* root, int* node_distance) {
        if (root == nullptr) {
            *node_distance = 0;
            return 0;
        }
        int left_max = get_max_distance_internal(root->left, node_distance);
        int left_node_distance = *node_distance;
        int right_max = get_max_distance_internal(root->right, node_distance);
        int right_node_distance = *node_distance;
        *node_distance = std::max(left_node_distance, right_node_distance) + 1;
        int node_max_distance = left_node_distance + right_node_distance + 1;
        return std::max(std::max(left_max, right_max), node_max_distance);
    }
};

TreeNode* get_binary_tree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = get_binary_tree();
    Solution s;
    int res = s.get_max_distance(root);
    std::cout << "max distance: " << res << std::endl;
    return 0;
}
