#include <vector>
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return std::vector<int>();
        }
        std::queue<TreeNode*> qu;
        std::vector<int> res;
        TreeNode* last = root;
        TreeNode* nlast = root;
        qu.push(root);
        while (!qu.empty()) {
            auto node = qu.front();
            qu.pop();
            if (node->left != nullptr) {
                qu.push(node->left);
                nlast = node->left;
            }
            if (node->right != nullptr) {
                qu.push(node->right);
                nlast = node->right;
            }
            if (last == node) {
                res.emplace_back(last->val);
                last = nlast;
            }
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    Solution s;
    auto res = s.rightSideView(root);
    for (const auto& x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}