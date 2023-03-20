#include <stack>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 此算法求的 slow 为中间元素
        ListNode* fast = head, *slow = head;
        for (; fast != nullptr && fast->next != nullptr;) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 如果是 fast == nullptr 表示链表的长度为偶数，slow 位于下半部分的第一位，这种情况我们不用管
        // 如果 fast->next = nullptr 表示链表的长度为奇数，slow 位于中心元素，让他在走一步
        // 注意这里要判断 fast != nullptr
        if (fast != nullptr && fast->next == nullptr) {
            slow = slow->next;
        }
        while (slow != nullptr) {
            st_.emplace(slow->val);
            slow = slow->next;
        }
        while (!st_.empty() && head != nullptr) {
            if (st_.top() != head->val) {
                return false;
            }
            st_.pop();
            head = head->next;
        }
        if (!st_.empty()) {
            return false;
        }
        return true;
    }

private:
    std::stack<int> st_;
};
