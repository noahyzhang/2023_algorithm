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

class Solution2 {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if (text1.empty() || text2.empty()) return 0;
        unsigned m = text1.size(), n = text2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        for (unsigned i = 1; i <= m; i++) {
            for (unsigned j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution3 {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        if (text2.size() < text1.size()) {
            std::swap(text1, text2);
        }
        std::vector<std::pair<int, int>> arr(text1.size() + 1, {0, 0});
        arr[0] = {0, 0};
        for (int i = 1; i < text1.size()+1; i++) {
            arr[i] = text1[i-1] == text2[0] ? std::pair<int, int>{0, 1} : std::pair<int, int>{0, 0};
        }
        print(arr);
        for (int i = 1; i < text2.size(); i++) {
            arr[0] = {0, 0};
            for (int j = 1; j < text1.size()+1; j++) {
                arr[j].first = arr[j].second;
                arr[j].second = text2[i] == text1[j-1] ? (arr[j-1].first + 1) : std::max(arr[j].first, arr[j-1].second);
            }
            print(arr);
        }
        return arr[text1.size()].second;
    }

private:
    void print(const std::vector<std::pair<int, int>>& arr) {
        for (const auto& x : arr) {
            std::cout << x.second << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    std::string str1 = "abcde";
    std::string str2 = "ace";
    int res = s.longestCommonSubsequence(str1, str2);
    std::cout << res << std::endl;

    Solution3 s3;
    int res3 = s3.longestCommonSubsequence(str1, str2);
    std::cout << res3 << std::endl;
    return 0;
}
