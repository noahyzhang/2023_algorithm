
#include <iostream>
#include <string>

// 给你一个url，原地反转
// 如https://www.baidu.com/dev-ops/question，反转后结果为https://question/ops-dev/com.baidu.www

class Solution {
public:
    void reserve_str(std::string& url) {
        int left = 0, right = url.size()-1;
        int count = 0;
        while (count != 2) {
            if (url[left] == '/') {
                count++;
            }
            left++;
        }
        int pos = left;
        // 先全部反转
        while (left < right) {
            std::swap(url[left++], url[right--]);
        }
        left = pos;
        for (int i = left; i < url.size(); i++) {
            if (url[i] == '/' || i == url.size()-1) {
                right = i == url.size()-1 ? i : i-1;
                while (left < right) {
                    std::swap(url[left++], url[right--]);
                }
                left = i+1;
            }
        }
    }
};

int main() {
    std::string str{"https://www.baidu.com/dev-ops/question"};
    Solution s;
    s.reserve_str(str);
    std::cout << str << std::endl;
    return 0;
}