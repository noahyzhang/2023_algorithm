#include <unordered_map>

struct DLinkNode {
    int key{0};
    int val{0};
    DLinkNode* prev{nullptr};
    DLinkNode* next{nullptr};

    DLinkNode() = default;
    DLinkNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    explicit LRUCache(int capacity)
        : size_(0), capacity_(capacity) {
        head_ = new DLinkNode();
        tail_ = new DLinkNode();
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key) {
        auto iter = mp_.find(key);
        if (iter == mp_.end()) {
            return -1;
        } else {
            delete_node(iter->second);
            add_head(iter->second);
            return iter->second->val;
        }
    }

    void put(int key, int value) {
        // 存在的情况下
        auto iter = mp_.find(key);
        if (iter != mp_.end()) {
            iter->second->val = value;
            delete_node(iter->second);
            add_head(iter->second);
        } else {  // 不存在的情况
            DLinkNode* node = new DLinkNode(key, value);
            mp_[key] = node;
            add_head(node);
            size_++;
            if (size_ > capacity_) {
                DLinkNode* node = remove_tail();
                mp_.erase(node->key);
                delete node;
                size_--;
            }
        }
    }

private:
    void delete_node(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add_head(DLinkNode* node) {
        node->prev = head_;
        node->next = head_->next;
        head_->next = node;
        node->next->prev = node;
    }

    DLinkNode* remove_tail() {
        DLinkNode* node = tail_->prev;
        delete_node(node);
        return node;
    }

private:
    int size_{0};
    int capacity_{0};
    DLinkNode* head_{nullptr};
    DLinkNode* tail_{nullptr};
    std::unordered_map<int, DLinkNode*> mp_;
};
