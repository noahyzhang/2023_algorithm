#include <vector>
#include <iostream>
#include <queue>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        std::priority_queue<WrapListNode> qu;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                qu.push({lists[i]->val, lists[i]});
            }
        }
        ListNode dummy;
        ListNode* res = &dummy;
        while (!qu.empty()) {
            ListNode* tmp = qu.top().node;
            qu.pop();
            res->next = tmp;
            res = res->next;
            if (tmp->next != nullptr) {
                qu.push({tmp->next->val, tmp->next});
            }
        }
        return dummy.next;
    }

private:
    struct WrapListNode {
        int val;
        ListNode* node;
        bool operator< (const WrapListNode& node) const {
            return val > node.val;
        }
    };
};

int main() {
    ListNode* node_5 = new ListNode(5);
    ListNode* node_4 = new ListNode(4, node_5);
    ListNode* node_1 = new ListNode(1, node_4);

    ListNode* head_4 = new ListNode(4);
    ListNode* head_3 = new ListNode(3, head_4);
    ListNode* head_1 = new ListNode(1, head_3);

    std::vector<ListNode*> lists{node_1, head_1};
    Solution s;
    auto res = s.mergeKLists(lists);
    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
