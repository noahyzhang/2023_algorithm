#include <string>
#include <iostream>
#include <unordered_map>

// leetcode：https://leetcode.cn/problems/design-authentication-manager/description/

// 哈希表的思路
// 这个实现并没有删除过期节点的功能
class AuthenticationManager {
public:
    explicit AuthenticationManager(int timeToLive) {
        time_to_live_ = timeToLive;
    }

    void generate(std::string tokenId, int currentTime) {
        mp_[tokenId] = currentTime + time_to_live_;
    }

    void renew(std::string tokenId, int currentTime) {
        auto iter = mp_.find(tokenId);
        if (iter != mp_.end() && iter->second > currentTime) {
            iter->second = currentTime + time_to_live_;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (const auto& x : mp_) {
            if (x.second > currentTime) {
                res++;
            }
        }
        return res;
    }

private:
    int time_to_live_;
    std::unordered_map<std::string, int> mp_;
};


// 哈希表+双向链表的思路
// 可以删除过期节点
struct Node {
public:
    int expire_;
    std::string key_;
    Node* prev_;
    Node* next_;

    explicit Node(int expire) : expire_(expire), prev_(nullptr), next_(nullptr) {}
    Node(int expire, std::string key) : expire_(expire), key_(key), prev_(nullptr), next_(nullptr) {}
    Node(int expire, std::string key, Node* prev, Node* next)
        : expire_(expire), key_(key), prev_(prev), next_(next) {}
};

class AuthenticationManager {
public:
    explicit AuthenticationManager(int timeToLive) {
        time_to_live_ = timeToLive;
        head_ = new Node(-1);
        tail_ = new Node(-1);
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }

    void generate(std::string tokenId, int currentTime) {
        Node* node = new Node(currentTime + time_to_live_, tokenId);
        mp_[tokenId] = node;
        Node* last = tail_->prev_;
        last->next_ = node;
        node->prev_ = last;
        tail_->prev_ = node;
        node->next_ = tail_;
    }

    void renew(std::string tokenId, int currentTime) {
        auto iter = mp_.find(tokenId);
        if (iter != mp_.end() && iter->second->expire_ > currentTime) {
            Node* node = mp_[tokenId];
            Node* prev = node->prev_;
            Node* next = node->next_;
            prev->next_ = next;
            next->prev_ = prev;
            node->expire_ = currentTime + time_to_live_;
            Node* last = tail_->prev_;
            last->next_ = node;
            node->prev_ = last;
            tail_->prev_ = node;
            node->next_ = tail_;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        while (head_->next_->expire_ > 0 && head_->expire_ <= currentTime) {
            Node* node = head_->next_;
            mp_.erase(node->key_);
            head_->next_ = node->next_;
            node->next_->prev_ = head_;
            delete node;
        }
        return mp_.size();
    }

private:
    int time_to_live_{0};
    Node* head_{nullptr};
    Node* tail_{nullptr};
    std::unordered_map<std::string, Node*> mp_;
};
