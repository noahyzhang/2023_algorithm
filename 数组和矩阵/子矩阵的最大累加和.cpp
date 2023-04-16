#include <vector>
#include <iostream>

class Solution {
public:
    int get_max_sum(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int max = 0;
        int cur = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            std::vector<int> sum_arr(matrix[0].size(), 0);
            for (int j = 0; j < matrix.size(); ++j) {
                cur = 0;
                for (int k = 0; k < sum_arr.size(); ++k) {
                    sum_arr[k] += matrix[j][k];
                    cur += sum_arr[k];
                    max = std::max(max, cur);
                    cur = cur < 0 ? 0 : cur;
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix{{-90, 48, 78}, {64, -40, 64}, {-81, -7, 66}};
    auto res = s.get_max_sum(matrix);
    std::cout << res << std::endl;
    return 0;
}
