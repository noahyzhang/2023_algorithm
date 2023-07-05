#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<int> st;
        int end = -1;
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                st.erase(s[i-1]);
            }
            while ((end+1 < n) && (st.find(s[end+1]) == st.end())) {
                st.insert(s[end+1]);
                end++;
            }
            res = std::max(res, end-i+1);
        }
        return res;
    }
};

int main() {
    std::string str("abcabcbb");
    Solution s;
    int len = s.lengthOfLongestSubstring(str);
    std::cout << len << std::endl;
    return 0;
}