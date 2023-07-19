#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string get_palindromel(const std::string& str) {
        if (str.size() < 2) {
            return str;
        }
        auto dp = get_dp(str);
        std::string res(str.size() + dp[0][str.size()-1], '0');
        int i = 0;
        int j = str.size() - 1;
        int res_left = 0;
        int res_right = res.size() - 1;
        while (i <= j) {
            if (str[i] == str[j]) {
                res[res_left++] = str[i++];
                res[res_right--] = str[j--];
            } else if (dp[i][j-1] < dp[i+1][j]) {
                res[res_left++] = str[j];
                res[res_right--] = str[j--];
            } else {
                res[res_left++] = str[i];
                res[res_right--] = str[i++];
            }
        }
        return res;
    }

private:
    std::vector<std::vector<int>> get_dp(const std::string& str) {
        std::vector<std::vector<int>> dp(str.size(), std::vector<int>(str.size(), 0));
        for (int j = 1; j < str.size(); j++) {
            dp[j-1][j] = str[j-1] == str[j] ? 0 : 1;
            for (int i = j-2; i > -1; i--) {
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp;
    }
};

int main() {
    Solution s;
    auto res = s.get_palindromel("AB");
    std::cout << res << std::endl;
    return 0;
}
