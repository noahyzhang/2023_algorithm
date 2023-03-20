
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 头节点肯定不会被删除
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = head, *next = nullptr;
        for (; cur != nullptr && cur->next != nullptr;) {
            next = cur->next;
            if (cur->val == next->val) {
                cur->next = next->next;
                delete next;
                continue;
            }
            cur = cur->next;
        }
        return head;
    }
};
