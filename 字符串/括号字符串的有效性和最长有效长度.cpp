#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool is_valid(const std::string& str) {
        if (str.size() < 2) {
            return false;
        }
        int status = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '(' && str[i] != ')') {
                return false;
            }
            if (str[i] == ')' && --status < 0) {
                return false;
            }
            if (str[i] == '(') {
                status++;
            }
        }
        return status == 0;
    }
};

class Solution2 {
public:
    int get_max_vaild_len(const std::string& str) {
        if (str.size() < 2) {
            return 0;
        }
        int res = 0;
        int pre = 0;
        std::vector<int> dp(str.size(), 0);
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == '(') {
                dp[i] = 0;
            }
            if (str[i] == ')') {
                pre = i - dp[i-1] - 1;
                if (pre >= 0 && str[pre] == '(') {
                    dp[i] = dp[i-1] + 2 + (pre-1 >= 0 ? dp[pre-1] : 0);
                }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

// https://leetcode.cn/problems/valid-parenthesis-string/
// 包括 * 号，判断有效
class Solution3 {
public:
    bool is_valid(const std::string& str) {
        if (str.empty()) {
            return true;
        }
        int min_value = 0;
        int max_value = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                min_value++;
                max_value++;
            } else if (str[i] == ')') {
                min_value = min_value != 0 ? --min_value : 0;
                max_value--;
            } else if (str[i] == '*') {
                min_value = min_value != 0 ? --min_value : 0;
                max_value++;
            }
            if (max_value < 0) {
                return false;
            }
        }
        return min_value == 0;
    }
};

int main() {
    // Solution2 s2;
    // int res = s2.get_max_vaild_len("()(()()(");
    Solution3 s3;
    auto res = s3.is_valid("(*))");
    std::cout << res << std::endl;
    return 0;
}
