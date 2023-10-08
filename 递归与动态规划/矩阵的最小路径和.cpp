#include <vector>
#include <iostream>

void print_vec(const std::vector<std::vector<int>>& vec) {
    for (const auto& x : vec) {
        for (const auto& y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        res[0][0] = grid[0][0];
        for (size_t i = 1; i < n; ++i) {
            res[0][i] = grid[0][i] + res[0][i-1];
        }
        for (size_t i = 1; i < m; ++i) {
            res[i][0] = grid[i][0] + res[i-1][0];
        }
        for (size_t row = 1; row < m; ++row) {
            for (size_t line = 1; line < n; ++line) {
                res[row][line] = std::min(res[row-1][line], res[row][line-1]) + grid[row][line];
            }
        }
        return res[m-1][n-1];
    }
};

// 空间压缩
class Solution2 {
public:
    int get_min_path_sum(const std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int more = std::max(grid.size(), grid[0].size());
        int less = std::min(grid.size(), grid[0].size());
        bool row_more = more == grid.size();
        std::vector<int> arr(less, 0);
        arr[0] = grid[0][0];
        for (int i = 1; i < less; i++) {
            arr[i] = arr[i-1] + (row_more ? grid[0][i] : grid[i][0]);
        }
        for (int i = 1; i < more; i++) {
            arr[0] = arr[0] + (row_more ? grid[i][0] : grid[0][i]);
            for (int j = 1; j < less; j++) {
                arr[j] = std::min(arr[j-1], arr[j]) + (row_more ? grid[i][j] : grid[j][i]);
            }
        }
        return arr[less-1];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    auto res = s.minPathSum(grid);
    std::cout << res << std::endl;
    Solution2 s2;
    auto res2 = s2.get_min_path_sum(grid);
    std::cout << res2 << std::endl;
    return 0;
}