#include <utility>

// 一个链表，特点是奇数位升序偶数位降序，使得链表变成升序的。

struct Node {
    int val;
    Node* next;

    explicit Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    std::pair<Node*, Node*> split_lists(Node* head) {
        Node* head1 = nullptr;
        Node* head2 = nullptr;
        Node* cur1 = nullptr;
        Node* cur2 = nullptr;
        int count = 1;
        while (head != nullptr) {
            if (count % 2 == 1) {
                if (head1 == nullptr) {
                    cur1 = head;
                    head1 = cur1;
                } else {
                    cur1->next = head;
                    cur1 = cur1->next;
                }
            } else {
                if (head2 == nullptr) {
                    cur2 = head;
                    head2 = cur2;
                } else {
                    cur2->next = head;
                    cur2 = cur2->next;
                }
            }
            count++;
            head = head->next;
        }
        cur1->next = nullptr;
        cur2->next = nullptr;
        return std::pair<Node*, Node*>{head1, head2};
    }

    Node* reverse_list(Node* head) {
        Node* pre = nullptr;
        Node* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    Node* combine_list(Node* head1, Node* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return head1 != nullptr ? head1 : head2;
        }
        Node* head = head1->val < head2->val ? head1 : head2;
        Node* cur1 = head == head1 ? head1 : head2;
        Node* cur2 = head == head1 ? head2 : head1;
        Node* pre = nullptr;
        Node* next = nullptr;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                pre = cur1;
                cur1 = cur1->next;
            } else {
                next = cur2->next;
                pre->next = cur2;
                cur2->next = cur1;
                pre = cur2;
                cur2 = next;
            }
        }
        pre->next = cur1 == nullptr ? cur2 : cur1;
        return head;
    }
};
