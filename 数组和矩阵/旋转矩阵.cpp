#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int lu_row = 0, lu_line = 0;
        int rd_row = matrix.size()-1, rd_line = matrix[0].size()-1;
        for (; lu_row < rd_row && lu_line < rd_line;) {
            rotate_edge(matrix, lu_row++, lu_line++, rd_row--, rd_line--);
        }
    }

private:
    void rotate_edge(std::vector<std::vector<int>>& matrix, int lu_row, int lu_line, int rd_row, int rd_line) {
        int count = rd_row - lu_row;
        int tmp = 0;
        for (int i = 0; i < count; ++i) {
            tmp = matrix[lu_row][lu_line+i];
            matrix[lu_row][lu_line+i] = matrix[rd_row-i][lu_line];
            matrix[rd_row-i][lu_line] = matrix[rd_row][rd_line-i];
            matrix[rd_row][rd_line-i] = matrix[lu_row+i][rd_line];
            matrix[lu_row+i][rd_line] = tmp;
        }
    }
};

void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    s.rotate(matrix);
    print_matrix(matrix);
    return 0;
}
