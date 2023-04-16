#include <vector>
#include <iostream>

class Solution {
public:
    int get_max_sum(const std::vector<int>& arr) {
        int max = 0;
        int cur = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
            cur += arr[i];
            if (cur > 0) {
                max = std::max(max, cur);
            } else if (cur < 0) {
                cur = 0;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{1, -2, 3, 5, -2, 6, -1};
    int res = s.get_max_sum(arr);
    std::cout << res << std::endl;
    return 0;
}