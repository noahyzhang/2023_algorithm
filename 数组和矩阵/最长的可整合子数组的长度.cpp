#include <vector>
#include <set>
#include <iostream>

class Solution {
public:
    int get_LIL(const std::vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int res = 0;
        int min = INT32_MAX;
        int max = INT32_MIN;
        std::set<int> st;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i; j < arr.size(); ++j) {
                if (st.find(arr[j]) != st.end()) {
                    break;
                }
                st.insert(arr[j]);
                min = std::min(min, arr[j]);
                max = std::max(max, arr[j]);
                if (max - min == j - i) {
                    res = std::max(res, j - i + 1);
                }
            }
            st.clear();
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{5, 5, 3, 2, 6, 4, 3};
    auto res = s.get_LIL(arr);
    std::cout << res << std::endl;
    return 0;
}
