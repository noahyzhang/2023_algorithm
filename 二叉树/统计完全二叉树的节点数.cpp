#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;
};

class Solution {
public:
    int get_nodes(const Node* head) {
        if (head == nullptr) {
            return 0;
        }
        return bs(head, 1, get_max_level(head, 1));
    }

private:
    int bs(const Node* head, int level, int high) {
        if (head == nullptr) {
            return 0;
        }
        if (get_max_level(head->right, level+1) == high) {
            return (1 << (high - level)) + bs(head->right, level+1, high);
        } else {
            return (1 << (high-level-1)) + bs(head->left, level+1, high);
        }
    }

    int get_max_level(const Node* head, int level) {
        while (head != nullptr) {
            head = head->left;
            level++;
        }
        return level - 1;
    }
};
