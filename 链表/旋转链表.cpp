
// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
// Leetcode: https://leetcode.cn/problems/rotate-list/description/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        ListNode* node = head;
        int len = 1;
        while (node->next != nullptr) {
            len++;
            node = node->next;
        }
        int add = len - k%len;
        if (add == len) {
            return head;
        }
        node->next = head;
        while (add--) {
            node = node->next;
        }
        ListNode* res = node->next;
        node->next = nullptr;
        return res;
    }
};
