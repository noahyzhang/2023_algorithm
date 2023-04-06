#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool is_deformation(const std::string& str1, const std::string& str2) {
        std::unordered_map<char, int> mp;
        for (const auto& x : str1) {
            mp[x]++;
        }
        for (const auto& x : str2) {
            mp[x]--;
        }
        for (const auto& x : mp) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::string str1 = "123";
    std::string str2 = "2331";
    bool res = s.is_deformation(str1, str2);
    std::cout << res << std::endl;
    return 0;
}