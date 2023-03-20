
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* fast = head, *slow = head;
        for (; fast != nullptr && k-- > 0;) {
            fast = fast->next;
        }
        for (; fast != nullptr && slow != nullptr;) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

ListNode* get_list(const std::vector<int>& vec) {
    ListNode* node = new ListNode(vec[0]);
    ListNode* tmp = node;
    for (size_t i = 1; i < vec.size(); ++i) {
        tmp->next = new ListNode(vec[i]);
        tmp = tmp->next;
    }
    return node;
}

void print_list(ListNode* node) {
    for (; node != nullptr;) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    ListNode* list = get_list({1, 2, 3, 4, 5});
    print_list(list);
    ListNode* node = s.getKthFromEnd(list, 2);
    print_list(node);
    return 0;
}
