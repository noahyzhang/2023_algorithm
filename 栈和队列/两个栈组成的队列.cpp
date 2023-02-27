#include <stack>
#include <iostream>

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        push_stack_.push(value);
    }

    int deleteHead() {
        if (pop_stack_.empty() && push_stack_.empty()) {
            return -1;
        }
        if (pop_stack_.empty()) {
            while (!push_stack_.empty()) {
                pop_stack_.push(push_stack_.top());
                push_stack_.pop();
            }
        }
        int val = pop_stack_.top();
        pop_stack_.pop();
        return val;
    }

private:
    std::stack<int> push_stack_;
    std::stack<int> pop_stack_;
};

int main() {
    CQueue c;
    std::cout << c.deleteHead() << std::endl;
    c.appendTail(5);
    c.appendTail(2);
    std::cout << c.deleteHead() << std::endl;
    std::cout << c.deleteHead() << std::endl;
}