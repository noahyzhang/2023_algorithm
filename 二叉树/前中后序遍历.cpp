#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <unistd.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

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

// 根左右
void pre_order_recur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    pre_order_recur(root->left);
    pre_order_recur(root->right);
}

void pre_order_recur_02(TreeNode* root) {
    std::stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        std::cout << node->val << " ";
        if (node->right) {
            st.push(node->right);
        }
        if (node->left) {
            st.push(node->left);
        }
    }
    std::cout << std::endl;
}

// 左根右
void in_order_recur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    in_order_recur(root->left);
    std::cout << root->val << " ";
    in_order_recur(root->right);
}

void in_order_recur_02(TreeNode* root) {
    std::stack<TreeNode*> st;
    while (root) {
        st.push(root);
        root = root->left;
    }
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        std::cout << node->val << " ";
        if (node->right) {
            TreeNode* right_node = node->right;
            while (right_node) {
                st.push(right_node);
                right_node = right_node->left;
            }
        }
    }
    std::cout << std::endl;
}

// 左右根
void post_order_recur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    post_order_recur(root->left);
    post_order_recur(root->right);
    std::cout << root->val << " ";
}

enum State { LEFT = 0, RIGHT, OUT };
struct Elem {
    TreeNode* node;
    State state;

    Elem(TreeNode* node, State state) : node(node), state(state) {}
};

void post_order_recur_02(TreeNode* root) {
    std::stack<std::shared_ptr<Elem>> st;
    st.push(std::make_shared<Elem>(root, LEFT));
    while (!st.empty()) {
        // 记住：这里如果是常规类型就是复制，下面的改动不会改到原数据
        auto elem = st.top();
        if (elem->state == LEFT) {
            elem->state = RIGHT;
            if (elem->node->left) {
                st.push(std::make_shared<Elem>(elem->node->left, LEFT));
                continue;
            }
        }
        if (elem->state == RIGHT) {
            elem->state = OUT;
            if (elem->node->right) {
                st.push(std::make_shared<Elem>(elem->node->right, LEFT));
                continue;
            }
        }
        if (elem->state == OUT) {
            std::cout << elem->node->val << " ";
            st.pop();
        }
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* node = gen_binary_tree();

    // pre_order_recur(node);
    // std::cout << std::endl;
    // pre_order_recur_02(node);

    // in_order_recur(node);
    // std::cout << std::endl;
    // in_order_recur_02(node);

    post_order_recur(node);
    std::cout << std::endl;
    post_order_recur_02(node);
}


