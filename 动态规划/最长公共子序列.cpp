#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if (text1.empty() || text2.empty()) return 0;
        std::vector<std::vector<int>> dp(text1.size(), std::vector<int>(text2.size(), 0));
        int max_val = 0;
        bool flag = false;
        for (int i = 0; i < text2.size(); ++i) {
            if (flag) {
                dp[0][i] = 1;
                continue;
            }
            if (text1[0] == text2[i]) {
                dp[0][i] = 1;
                flag = true;
                max_val = 1;
            }
        }
        flag = false;
        for (int i = 0; i < text1.size(); ++i) {
            if (flag) {
                dp[i][0] = 1;
                continue;
            }
            if (text2[0] == text1[i]) {
                dp[i][0] = 1;
                flag = true;
                max_val = 1;
            }
        }
        for (int i = 1; i < text1.size(); ++i) {
            for (int j = 1; j < text2.size(); ++j) {
                int val = 0;
                if (text1[i] == text2[j]) {
                    val = dp[i-1][j-1] + 1;
                }
                dp[i][j] = std::max(val, std::max(dp[i-1][j], dp[i][j-1]));
                if (dp[i][j] > max_val) {
                    max_val = dp[i][j];
                }
            }
        }
        return max_val;
    }
};

int main() {
    Solution s;
    std::string str1 = "abcde";
    std::string str2 = "ace";
    int res = s.longestCommonSubsequence(str1, str2);
    std::cout << res << std::endl;
    return 0;
}
