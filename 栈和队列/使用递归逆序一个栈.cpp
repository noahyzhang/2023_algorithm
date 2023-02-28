#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void push(std::vector<int> vec) {
        std::for_each(vec.begin(), vec.end(), [&](int val) {
            st.push(val);
        });
    }
    void print() {
        std::stack<int> tmp_st;
        while (!st.empty()) {
            tmp_st.push(st.top());
            st.pop();
        }
        while (!tmp_st.empty()) {
            int val = tmp_st.top();
            std::cout << val << " ";
            st.push(val);
            tmp_st.pop();
        }
        std::cout << std::endl;
    }
    void reverse_stack() {
        if (st.empty()) {
            return;
        }
        // 比如插入业务栈是 1、2、3、4、5，业务栈元素从底到顶为 1、2、3、4、5
        // 这里获取到的元素的顺序为 1、2、3、4、5
        int last = get_stack_bottom_elem();
        reverse_stack();
        // 当业务栈为空，最后一次获取的元素即为 5。则插入顺序变为 5、4、3、2、1。即可实现逆序
        st.push(last);
    }

private:
    //  获取栈底元素并出栈
    int get_stack_bottom_elem() {
        // 这个 result 就是通过操作系统栈来保存业务栈的每一个元素
        // 只不过仅仅返回业务栈最底的元素
        int result = st.top();
        st.pop();
        if (st.empty()) {
            return result;
        } else {
            // last 获取到业务栈底的元素，保存起来，依次返回出去，直到递归结束
            int last = get_stack_bottom_elem();
            // 重新将业务栈的元素插回去
            st.push(result);
            return last;
        }
    }

private:
    std::stack<int> st;
};

int main() {
    Solution s;
    s.push({1, 2, 3, 4, 5});
    s.print();
    s.reverse_stack();
    s.print();
}
