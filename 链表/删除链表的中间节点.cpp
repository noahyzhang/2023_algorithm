#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
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

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // 空链表和长度为 1 的链表直接返回
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        // 长度为 2 的链表，要更新头节点
        if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }
        // 其余情况
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = slow;
        for (; fast != nullptr && fast->next != nullptr;) {
            fast = fast->next->next;
            // 在 slow 走之前先保存他的前一个节点
            prev = slow;
            slow = slow->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = get_list({1});
    print_list(head);
    ListNode* res = s.deleteMiddle(head);
    print_list(res);
    return 0;
}
