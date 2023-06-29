#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int get_index(const std::vector<std::string>& strs, const std::string& str) {
        if (strs.empty() || str.empty()) {
            return -1;
        }
        int left = 0, right = strs.size() - 1;
        int res = -1;
        int mid = 0;
        for (; left < right;) {
            mid = left + (right - left) >> 1;
            if (!strs[mid].empty() && equals(strs[mid], str)) {
                res = mid;
                right = mid - 1;
            } else if (!strs[mid].empty()) {
                if (compare(strs[mid], str)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                int index = mid;
                for (; strs[index].empty() && --index >= left;) {}
                if (index < left || !compare(strs[index], str)) {
                    left = mid + 1;
                } else {
                    res = equals(strs[index], str) ? index : res;
                    right = index - 1;
                }
            }
        }
        return res;
    }

private:
    // 判断字典序
    // str1 > str2  return true
    // str1 < str1  return false
    bool compare(const std::string& str1, const std::string& str2) {
        return str1.compare(str2) > 0;
    }
    // 判断相等
    bool equals(const std::string& str1, const std::string& str2) {
        return str1 == str2;
    }
};

int main() {
    Solution s;
    std::vector<std::string> arr{"", "a", "", "a", "", "b", "", "c"};
    auto res = s.get_index(arr, "a");
    std::cout << res << std::endl;
    return 0;
}