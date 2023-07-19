#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int get_max_length_substr(const std::string& str) {
        if (str.empty()) {
            return 0;
        }
        std::unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); ++i) {
            mp[str[i]] = -1;
        }
        int res = 0;
        int pre = -1;
        for (int i = 0; i < str.size(); ++i) {
            pre = std::max(pre, mp[str[i]]);
            res = std::max(res, i - pre);
            mp[str[i]] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    int res = s.get_max_length_substr("abccdsd");
    std::cout << "res: " << res << std::endl;
    return 0;
}

