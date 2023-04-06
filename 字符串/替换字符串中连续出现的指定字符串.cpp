#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    std::string replace(const std::string& str, const std::string& from, const std::string& to) {
        if (str.empty()) return "";
        std::string res(str);
        int match = 0;
        for (size_t i = 0; i < res.size(); ++i) {
            // 如果到达了最后一个位置了
            if (match == from.size()-1) {
                if (res[i] == from[match]) {
                    match = 0;
                    for (int j = i, count = from.size(); count > 0; j--, count--) {
                        res[j] = 0;
                    }
                    continue;
                }
                match = 0;
                continue;
            }
            if (res[i] == from[match]) {
                match++;
            } else {
                match = 0;
            }
        }
        std::stringstream oss;
        if (res[0] == 0) oss << to;
        auto begin = res.begin(), end = res.begin();
        bool begin_flag = false;
        for (auto iter = res.begin(); iter != res.end(); ++iter) {
            if (begin_flag == false) {
                if (*iter != 0) {
                    begin = iter;
                    begin_flag = true;
                }
                continue;
            }
            if (*iter == 0) {
                end = iter;
                oss << std::string(begin, end) << to;
                begin_flag = false;
            }
        }
        return oss.str();
    }
};

int main() {
    Solution s;
    auto res = s.replace("abcabc123abcabc456abcabc", "abc", "X");
    std::cout << res << std::endl;
    return 0;
}
