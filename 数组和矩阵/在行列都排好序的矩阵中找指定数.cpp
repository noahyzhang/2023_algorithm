#include <vector>
#include <iostream>

class Solution {
public:
    bool findNumberIn2DArray(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        // 从右上角开始找
        int row = 0, line = matrix[0].size() - 1;
        for (; row < matrix.size() && line >= 0;) {
            int val = matrix[row][line];
            if (val == target) {
                return true;
            } else if (val > target) {
                line--;
            } else if (val < target) {
                row++;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> matrix{{0, 1, 2, 5}, {2, 3, 4, 7}, {4, 4, 4, 8}, {5, 7, 7, 9}};
    Solution s;
    auto res = s.findNumberIn2DArray(matrix, 6);
    std::cout << (res ? "true" : "false") << std::endl;
}