#include <unordered_map>
#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

int pre_order(const Node* const head, int sum,
    int pre_sum, int level, int max_len, std::unordered_map<int, int>& mp) {
    if (head == nullptr) {
        return max_len;
    }
    int cur_sum = pre_sum + head->value;
    if (mp.find(cur_sum) == mp.end()) {
        mp[cur_sum] = level;
    }
    if (mp.find(cur_sum - sum) != mp.end()) {
        max_len = std::max(max_len, level - mp[cur_sum - sum]);
    }
    max_len = pre_order(head->left, sum, cur_sum, level+1, max_len, mp);
    max_len = pre_order(head->right, sum, cur_sum, level+1, max_len, mp);
    if (mp[cur_sum] == level) {
        mp.erase(cur_sum);
    }
    return max_len;
}

int get_max_length(const Node* const head, int sum) {
    std::unordered_map<int, int> mp;
    mp.emplace(0, 0);
    pre_order(head, sum, 0, 1, 0, mp);
}

int main() {
    Node* head = new Node(-3);
    head->left = new Node(3);
    head->right = new Node(-9);
    head->left->left = new Node(1);
    head->left->right = new Node(0);
    head->left->right->left = new Node(1);
    head->left->right->right = new Node(6);
    head->right->left = new Node(2);
    head->right->right = new Node(1);
    int max_len = get_max_length(head, 6);
    std::cout << max_len << std::endl;
    return 0;
}