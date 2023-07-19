#include <vector>
#include <iostream>

class Solution {
public:
    int min_coins(const std::vector<int>& arr, int aim) {
        if (arr.empty() || aim < 0) {
            return -1;
        }
        int n = arr.size();
        int32_t max = INT32_MAX;
        std::vector<std::vector<int>> dp(n, std::vector<int>(aim+1, 0));
        for (int j = 1; j <= aim; ++j) {
            dp[0][j] = max;
            if (j - arr[0] >= 0 && dp[0][j-arr[0]] != max) {
                dp[0][j] = dp[0][j-arr[0]] + 1;
            }
        }
        int left = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= aim; ++j) {
                left = max;
                if (j - arr[i] >= 0 && dp[i][j-arr[i]] != max) {
                    left = dp[i][j-arr[i]] + 1;
                }
                dp[i][j] = std::min(left, dp[i-1][j]);
            }
        }
        return dp[n-1][aim] != max ? dp[n-1][aim] : -1;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{5, 2, 5, 2};
    auto res = s.min_coins(arr, 10);
    std::cout << res << std::endl;
    return 0;
}
