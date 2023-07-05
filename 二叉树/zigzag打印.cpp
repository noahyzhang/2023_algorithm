#include <deque>
#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* left;
    Node* right;

    explicit Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void print_zigzag(Node* head) {
        std::deque<Node*> deq;
        deq.emplace_front(head);
        Node* last = head;
        Node* nlast = nullptr;
        bool lr = true;  // 从左到右
        int level = 1;
        print_data(level++, lr);
        Node* tmp = nullptr;
        for (; !deq.empty();) {
            if (lr) {
                tmp = deq.front();
                deq.pop_front();
                if (tmp->left != nullptr) {
                    nlast = nlast == nullptr ? tmp->left : nlast;
                    deq.emplace_back(tmp->left);
                }
                if (tmp->right != nullptr) {
                    nlast = nlast == nullptr ? tmp->right : nlast;
                    deq.emplace_back(tmp->right);
                }
            } else {
                tmp = deq.back();
                deq.pop_back();
                if (tmp->right != nullptr) {
                    nlast = nlast == nullptr ? tmp->right : nlast;
                    deq.emplace_front(tmp->right);
                }
                if (tmp->left != nullptr) {
                    nlast = nlast == nullptr ? tmp->left : nlast;
                    deq.emplace_front(tmp->left);
                }
            }

            std::cout << tmp->val << ", ";
            if (last == tmp && !deq.empty()) {
                lr = !lr;
                last = nlast;
                nlast = nullptr;
                std::cout << std::endl;
                print_data(level++, lr);
            }
        }
        std::cout << std::endl;
    }

private:
    void print_data(int level, bool lr) {
        std::cout << "level: " << level;
        std::cout << (lr == true ? ", from left to right: " : ", from right to left: ");
    }
};


class Solution2 {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(Node* root) {
        if (root == nullptr) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> res;
        deq.push_back(root);
        Node* last = root;
        Node* nlast = nullptr;
        bool flag = true;
        Node* tmp = nullptr;
        std::vector<int> median;
        while (!deq.empty()) {
            if (flag) {
                tmp = deq.front();
                deq.pop_front();
                if (tmp->left != nullptr) {
                    nlast = nlast == nullptr ? tmp->left : nlast;
                    deq.emplace_back(tmp->left);
                }
                if (tmp->right != nullptr) {
                    nlast = nlast == nullptr ? tmp->right : nlast;
                    deq.emplace_back(tmp->right);
                }
            } else {
                tmp = deq.back();
                deq.pop_back();
                if (tmp->right != nullptr) {
                    nlast = nlast == nullptr ? tmp->right : nlast;
                    deq.emplace_front(tmp->right);
                }
                if (tmp->left != nullptr) {
                    nlast = nlast == nullptr ? tmp->left : nlast;
                    deq.emplace_front(tmp->left);
                }
            }
            median.emplace_back(tmp->val);
            if (tmp == last) {
                last = nlast;
                nlast = nullptr;
                flag = !flag;
                res.emplace_back(median);
                median.clear();
            }
        }
        return res;
    }

private:
    std::deque<Node*> deq;
};

int main() {
    Solution s;
    Solution2 s2;
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(5);
    head->right->right = new Node(6);
    head->right->left->left = new Node(7);
    head->right->left->right = new Node(8);
    // s.print_zigzag(head);
    auto res = s2.zigzagLevelOrder(head);
    for (const auto& x : res) {
        for (const auto& y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}