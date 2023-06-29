#include <iostream>
#include <vector>
#include <queue>

void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& arr : matrix) {
        for (const auto& x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {
public:
    int get_min_path_value(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0][0] == 0
            || matrix[matrix.size()-1][matrix[0].size()-1] == 0) {
            return 0;
        }
        int rows = matrix.size(), lines = matrix[0].size();
        std::vector<std::vector<int>> mp(rows, std::vector<int>(lines, 0));
        std::queue<std::pair<int, int>> qu;
        qu.push({0, 0});
        mp[0][0] = 1;
        for (; !qu.empty();) {
            auto& node = qu.front();
            qu.pop();
            int row = node.first, line = node.second;
            if (row == rows-1 && line == lines-1) {
                print_matrix(mp);
                return mp[row][line];
            }
            go_walk(matrix, mp, mp[row][line], row-1, line, qu);
            go_walk(matrix, mp, mp[row][line], row+1, line, qu);
            go_walk(matrix, mp, mp[row][line], row, line-1, qu);
            go_walk(matrix, mp, mp[row][line], row, line+1, qu);
            print_matrix(mp);
        }
        return 0;
    }

private:
    void go_walk(
        const std::vector<std::vector<int>>& matrix,
        std::vector<std::vector<int>>& mp,
        int pre,
        int row, int line,
        std::queue<std::pair<int, int>>& qu) {
        if (row < 0 || line < 0 || row >= matrix.size() || line >= matrix[0].size()
            || matrix[row][line] == 0 || mp[row][line] != 0) {
            return;
        }
        mp[row][line] = pre+1;
        qu.push({row, line});
    }
};

int main() {
    std::vector<std::vector<int>> matrix{
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
    };
    Solution s;
    auto res = s.get_min_path_value(matrix);
    std::cout << res << std::endl;
    return 0;
}
