#include <string>
#include <iostream>

class Solution {
public:
    int strToInt(std::string str) {
        if (str.empty()) return 0;
        size_t cur = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                cur++;
            } else {
                break;
            }
        }
        if (!((str[cur] >= '0' && str[cur] <= '9') || (str[cur] == '+') || (str[cur] == '-'))) {
            return 0;
        }
        bool posi = true;
        if (str[cur] == '+') {
            posi = true;
            cur++;
        } else if (str[cur] == '-') {
            posi = false;
            cur++;
        }
        int min_q = INT32_MIN / 10;
        int min_r = INT32_MIN % 10;
        int res = 0;
        int tmp = 0;
        for (int i = cur; i < str.size(); ++i) {
            if (str[i] > '9' || str[i] < '0') {
                break;
            }
            tmp = '0' - str[i];
            if ((res < min_q) || (res == min_q && tmp < min_r)) {
                return posi ? INT32_MAX : INT32_MIN;
            }
            res = res * 10 + tmp;
        }
        if (posi && res == INT32_MIN) {
            return INT32_MAX;
        }
        return posi ? -res : res;
    }
};

int main() {
    Solution s;
    int val = s.strToInt("2147483648");
    std::cout << val << std::endl;
    return 0;
}
