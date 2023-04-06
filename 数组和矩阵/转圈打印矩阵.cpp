#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        // 左上角的坐标
        int lu_row = 0, lu_line = 0;
        // 右下角的坐标
        int rd_row = matrix.size() - 1, rd_line = matrix[0].size() - 1;
        for (; lu_row <= rd_row && lu_line <= rd_line;) {
            for (int i = lu_line; i <= rd_line; ++i) {
                res.emplace_back(matrix[lu_row][i]);
            }
            for (int i = lu_row+1; i <= rd_row; ++i) {
                res.emplace_back(matrix[i][rd_line]);
            }
            // 如果只有一行或者一列的情况下，就不用在遍历了
            if (lu_row == rd_row || lu_line == rd_line) {
                // 注意一定要是 break，不能是 continue，因为这种情况下已经遍历了中心哪一行/哪一列
                // 如果使用 continue，还会造成条件没有改变导致的死循环
                break;
            }
            for (int i = rd_line-1; i >= lu_line; --i) {
                res.emplace_back(matrix[rd_row][i]);
            }
            for (int i = rd_row-1; i > lu_row; --i) {
                res.emplace_back(matrix[i][lu_line]);
            }
            lu_row++, rd_row--;
            lu_line++, rd_line--;
        }
        return res;
    }
};

void print(const std::vector<int>& vec) {
    for (const auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    // std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // std::vector<std::vector<int>> matrix{{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}};
    std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto res = s.spiralOrder(matrix);
    print(res);
    return 0;
}
