#include <vector>

class Solution {
public:
    int change(int amount, const std::vector<int>& coins) {
        std::vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
