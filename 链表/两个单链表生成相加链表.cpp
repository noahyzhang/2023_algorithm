#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr, *tmp_node = nullptr;
        int ca = 0;
        for (; l1 != nullptr || l2 != nullptr;) {
            int cur_data = 0;
            if (l1 != nullptr) {
                cur_data += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                cur_data += l2->val;
                l2 = l2->next;
            }
            cur_data += ca;
            if (cur_data >= 10) {
                cur_data -= 10;
                ca = 1;
            } else {
                ca = 0;
            }
            ListNode* tmp = new ListNode(cur_data);
            if (res == nullptr) {
                res = tmp;
                tmp_node = tmp;
            } else {
                tmp_node->next = tmp;
                tmp_node = tmp_node->next;
            }
        }
        if (ca != 0) {
            ListNode* tmp = new ListNode(ca);
            tmp_node->next = tmp;
        }
        return res;
    }
};
