
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head, *next = nullptr;
        for (; curr != nullptr;) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

void print_list(ListNode* node) {
    for (; node != nullptr; node = node->next) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;
}

ListNode* gen_list(const std::vector<int> vec) {
    ListNode* root = new ListNode(vec[0]);
    ListNode* tmp = root;
    for (size_t i = 1; i < vec.size(); ++i) {
        tmp->next = new ListNode(vec[i]);
        tmp = tmp->next;
    }
    return root;
}

int main() {
    ListNode* root = gen_list({1, 2, 3, 4, 5, 6, 7});
    print_list(root);
    Solution s;
    ListNode* res = s.reverseList(root);
    print_list(res);
    return 0;
}