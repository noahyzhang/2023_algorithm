#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* left = head;
        for (; left->next != nullptr; left = left->next) {
            for (ListNode* right = left->next; right != nullptr; right = right->next) {
                if (left->val > right->val) {
                    int tmp = left->val;
                    left->val = right->val;
                    right->val = tmp;
                }
            }
        }
        return head;
    }
};

void print_list(ListNode* node) {
    for (; node != nullptr;) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution s;
    head = s.sortList(head);
    print_list(head);
    return 0;
}
