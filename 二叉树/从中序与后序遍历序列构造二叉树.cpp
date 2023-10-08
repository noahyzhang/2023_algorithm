
#include <vector>
#include <iostream>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(const std::vector<int>& inorder, const std::vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        pos_ = postorder.size()-1;
        int idx = 0;
        for (const auto& x : inorder) {
            mp_[x] = idx++;
        }
        return helper(0, postorder.size()-1, inorder, postorder);
    }

private:
    TreeNode* helper(int left, int right, const std::vector<int>& in_order, const std::vector<int>& post_order) {
        if (left > right) {
            return nullptr;
        }
        int root_val = post_order[pos_];
        TreeNode* node = new TreeNode(root_val);

        int index = mp_[root_val];
        pos_--;
        node->right = helper(index+1, right, in_order, post_order);
        node->left = helper(left, index-1, in_order, post_order);
        return node;
    }

private:
    std::unordered_map<int, int> mp_;
    int pos_{0};
};

