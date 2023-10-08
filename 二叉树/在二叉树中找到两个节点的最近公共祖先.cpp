#include <unordered_map>
#include <functional>
#include <mutex>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 给定的两个节点一个为 p，一个为 q
// 当前节点记为 cur，他的左子树记为 left，他的右子树记为 right
// 我们需要 left 和 right 的值来做逻辑判断，因此很适合用后序遍历。
// 1. 左右子树在遍历的过程中，如果遇到 p 或者 q 或者 null，直接返回 p 或者 q 或者 null
// 2. 左右子树都返回 null，则说明 cur 的整颗树上都没有发现 p 或者 q，返回 null
// 3. 左右子树都返回不为空，则说明 cur 的树上发现了 p 或者 q。cur 就是公共祖先节点
// 4. 左右子树有一个返回不为空，要么发现了 p 或者 q，要么 cur 已经是最近的公共祖先节点，直接返回 cur 即可


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

class Helper {
public:
    explicit Helper(TreeNode* head) {
        init_map(head);
        set_map(head);
    }

    TreeNode* query(TreeNode* node1, TreeNode* node2) {

        // for (const auto& x : mp_) {
        //     for (const auto& y : x.second) {
        //         std::cout << x.first->val << " " << y.first->val << " " << y.second->val << std::endl;
        //     }
        // }

        if (node1 == node2) {
            return node1;
        }
        auto node1_iter = mp_.find(node1);
        if (node1_iter != mp_.end()) {
            auto node2_iter = (*node1_iter).second.find(node2);
            if (node2_iter != (*node1_iter).second.end()) {
                return (*node2_iter).second;
            }
        }

        auto iter2 = mp_.find(node2);
        if (iter2 != mp_.end()) {
            auto iter1 = (*iter2).second.find(node1);
            if (iter1 != (*iter2).second.end()) {
                return (*iter1).second;
            }
        }
        return nullptr;
    }

private:
    void init_map(TreeNode* head) {
        if (head == nullptr) return;
        mp_[head] = std::unordered_map<TreeNode*, TreeNode*>();
        init_map(head->left);
        init_map(head->right);
    }

    void set_map(TreeNode* head) {
        if (head == nullptr) return;
        head_record(head->left, head);
        head_record(head->right, head);
        sub_record(head);
        set_map(head->left);
        set_map(head->right);
    }

    void head_record(TreeNode* node, TreeNode* head) {
        if (node == nullptr) return;
        mp_[node][head] = head;
        head_record(node->left, head);
        head_record(node->right, head);
    }

    void sub_record(TreeNode* head) {
        if (head == nullptr) return;
        pre_left(head->left, head->right, head);
        sub_record(head->left);
        sub_record(head->right);
    }

    void pre_left(TreeNode* left, TreeNode* right, TreeNode* head) {
        if (left == nullptr) {
            return;
        }
        pre_right(left, right, head);
        pre_left(left->left, right, head);
        pre_left(left->right, right, head);
    }

    void pre_right(TreeNode* left, TreeNode* right, TreeNode* head) {
        if (right == nullptr) return;
        mp_[left][right] = head;
        pre_right(left, right->left, head);
        pre_right(left, right->right, head);
    }

private:
    std::unordered_map<TreeNode*, std::unordered_map<TreeNode*, TreeNode*>> mp_;
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Helper helper(root);
        return helper.query(p, q);
    }
};

int main() {
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2);
    node2->left = node7;
    node2->right = node4;
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5);
    node5->left = node6;
    node5->right = node2;
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node1 = new TreeNode(1);
    node1->left = node0;
    node1->right = node8;
    TreeNode* node3 = new TreeNode(3);
    node3->left = node5;
    node3->right = node1;

    Solution2 s2;
    auto res = s2.lowestCommonAncestor(node3, node5, node4);
    if (res != nullptr) {
        std::cout << res->val << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }
    return 0;
}
