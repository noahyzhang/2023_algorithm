#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void level_recur(TreeNode* root) {
    TreeNode* last = root;
    TreeNode* nlast = nullptr;
    std::queue<TreeNode*> qu;
    qu.push(root);
    int count = 1;
    std::cout << "Level " << count << ": ";
    while (!qu.empty()) {
        TreeNode* node = qu.front();
        qu.pop();
        std::cout << node->val << " ";
        if (node->left) {
            qu.push(node->left);
            nlast = node->left;
        }
        if (node->right) {
            qu.push(node->right);
            nlast = node->right;
        }
        if (node == last && !qu.empty()) {
            last = nlast;
            std::cout << std::endl << "Level " << ++count << ": ";
        }
    }
    std::cout << std::endl;
}

TreeNode* gen_binary_tree() {
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->left->right = new TreeNode(6);
    node->right->left = new TreeNode(5);
    node->right->left->right = new TreeNode(7);
    return node;
}

int main() {
    TreeNode* root = gen_binary_tree();
    level_recur(root);
    return 0;
}