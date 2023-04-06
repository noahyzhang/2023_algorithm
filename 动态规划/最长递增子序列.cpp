#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        std::vector<int> dp(nums.size(), 0);
        int max_val = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (size_t j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            if (dp[i] > max_val) {
                max_val = dp[i];
            }
        }
        return max_val;
    }
};

class Solution_02 {
public:
    std::vector<int> lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return std::vector<int>();
        std::vector<int> dp(nums.size(), 0);
        int max_pos = 0, max_val = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (size_t j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            if (dp[i] > max_val) {
                max_val = dp[i];
                max_pos = i;
            }
        }
        std::vector<int> res;
        res.emplace_back(nums[max_pos]);
        int prev = max_pos;
        for (int i = max_pos-1; i >= 0; --i) {
            if (dp[i] == dp[prev]-1) {
                res.emplace_back(nums[i]);
                prev = i;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

void print_vec(const std::vector<int>& vec) {
    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution_02 s;
    std::vector<int> vec{2, 1, 5, 3, 6, 4, 8, 9, 7};
    auto res = s.lengthOfLIS(vec);
    print_vec(res);
    return 0;
}
