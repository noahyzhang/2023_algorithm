#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        get_hight(root, 1, res);
        return res;
    }

private:
    int get_hight(TreeNode* node, int level, bool& res) {
        if (node == nullptr) {
            return level;
        }
        int left_high = get_hight(node->left, level+1, res);
        if (!res) {
            return level;
        }
        int right_high = get_hight(node->right, level+1, res);
        if (!res) {
            return level;
        }
        if (std::abs(left_high - right_high) > 1) {
            res = false;
        }
        return std::max(left_high, right_high);
    }
};
