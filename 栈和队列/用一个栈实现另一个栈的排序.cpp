#include <stack>
#include <iostream>

class SortedStack {
public:
    SortedStack() {}

    void push(int val) {
        // 小于等于 top 值，直接插入
        if (st_.empty() || val <= st_.top()) {
            st_.push(val);
            return;
        }
        for (; !st_.empty() && st_.top() <= val ;) {
            help_st_.push(st_.top());
            st_.pop();
        }
        st_.push(val);
        for (; !help_st_.empty();) {
            st_.push(help_st_.top());
            help_st_.pop();
        }
    }

    void pop() {
        if (!st_.empty()) {
            st_.pop();
        }
    }

    int peek() {
        if (!st_.empty()) {
            return st_.top();
        }
        return -1;
    }

    bool isEmpty() {
        return st_.empty();
    }

private:
    std::stack<int> st_;
    std::stack<int> help_st_;
};

int main() {
    SortedStack s;
    s.pop();
    s.pop();
    s.push(1);
    s.pop();
    s.isEmpty();
    // s.push(1);
    // s.push(2);
    // std::cout << s.peek() << std::endl;
    // s.pop();
    // std::cout << s.peek() << std::endl;
}
