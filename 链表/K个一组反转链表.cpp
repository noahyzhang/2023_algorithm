#include <utility>

struct ListNode {
    int val{0};
    ListNode* next{nullptr};
    explicit ListNode(int v) : val(v) {}
};

class Solution {
public:
    ListNode* reverse_k_group(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (head != nullptr) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (tail == nullptr) {
                    return dummy->next;
                }
            }
            ListNode* nex = tail->next;
            std::pair<ListNode*, ListNode*> res = reverse_link(head, tail);
            head = res.first;
            tail = res.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }

private:
    std::pair<ListNode*, ListNode*> reverse_link(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        ListNode* nex = nullptr;
        while (prev != tail) {
            nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
};