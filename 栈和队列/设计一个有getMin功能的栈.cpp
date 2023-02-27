#include <stack>
#include <iostream>

template <typename T>
class MinStack {
public:
    MinStack() = default;

    void push(const T& data) {
        stack_data_.push(data);
        if (__glibc_unlikely(stack_min_.empty())) {
            stack_min_.push(data);
        } else {
            auto min_val = std::min(stack_min_.top(), data);
            stack_min_.push(min_val);
        }
    }
    void pop() {
        if (!stack_data_.empty() && !stack_min_.empty()) {
            stack_data_.pop();
            stack_min_.pop();
        }
    }
    T top() {
        T top_val;
        if (!stack_data_.empty() && !stack_min_.empty()) {
            return stack_data_.top();
        }
        return top_val;
    }
    T get_min() {
        T min_val;
        if (!stack_data_.empty() && !stack_min_.empty()) {
            min_val = stack_min_.top();
        }
        return min_val;
    }
private:
    std::stack<T> stack_data_;
    std::stack<T> stack_min_;
};

int main() {
    MinStack<int> s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    std::cout << s.get_min() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.get_min() << std::endl;
    return 0;
}
