#include <vector>
#include <algorithm>

struct Node {
    int val;
    Node* left;
    Node* right;

    explicit Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void adjust_node(Node* head) {
        in_order(head);
        set_err_pos();
        reserve(head, 2);
    }

private:
    void in_order(Node* head) {
        if (head == nullptr) {
            return;
        }
        in_order(head->left);
        vec_.emplace_back(head->val);
        in_order(head->right);
    }

    void set_err_pos() {
        int head1 = -1;
        int head2 = -1;
        for (int i = 0; i < vec_.size()-1; i++) {
            if (vec_[i] > vec_[i+1]) {
                head2 = i+1;
                if (head1 == -1) {
                    head1 = i;
                } else {
                    break;
                }
            }
        }
        err_pos_.first = vec_[head1];
        err_pos_.second = vec_[head2];
    }

    void reserve(Node* head, int count) {
        if (head == nullptr) {
            return;
        }
        if (head->val == err_pos_.first || head->val == err_pos_.second) {
            head->val = head->val == err_pos_.first ? err_pos_.second : err_pos_.first;
            count--;
        }
        if (count == 0) {
            return;
        }
        reserve(head->left, count);
        reserve(head->right, count);
    }

private:
    std::vector<int> vec_;
    std::pair<int, int> err_pos_;
};
