#include <iostream>
#include <vector>

// 暴力递归
class Solution {
public:
    int way(int N, int M, int K, int P) {
        if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N) {
            return 0;
        }
        return walk(N, M, K, P);
    }

private:
    int walk(int N, int cur, int rest, int p) {
        if (rest == 0) {
            return cur == p ? 1 : 0;
        }
        if (cur == 1) {
            return walk(N, 2, rest-1, p);
        }
        if (cur == N) {
            return walk(N, N-1, rest-1, p);
        }
        return walk(N, cur-1, rest-1, p) + walk(N, cur+1, rest-1, p);
    }
};

// 动态规划
// 一共 N 个位置，当前在 M 位置，可以走 K 步，到达 P 位置
class Solution2 {
public:
    int way(int N, int M, int K, int P) {
        if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N) {
            return 0;
        }
        std::vector<std::vector<int>> dp(K+1, std::vector<int>(N+1, 0));
        dp[0][P] = 1;
        for (size_t i = 1; i <= K; ++i) {
            for (size_t j = 1; j <= N; ++j) {
                if (j == 1) {
                    dp[i][1] = dp[i-1][2];
                } else if (j == N) {
                    dp[i][N] = dp[i-1][N-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                }
            }
        }
        return dp[K][M];
    }
};

int main() {
    // way 01
    Solution2 s;
    // int res = s.way(5, 2, 3, 3);
    int res = s.way(5000, 4548, 5000, 1600);
    std::cout << res << std::endl;

    return 0;
}
