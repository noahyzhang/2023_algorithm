#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& mat) {
        std::vector<int> res;
        if (mat.empty()) {
            return res;
        }
        int row = mat.size() - 1, line = mat[0].size() - 1;
        int tr = 0, tc = 0;
        int dr = 0, dc = 0;
        bool flag = true;
        for (; tr <= row && tc <= line && dr <= row && dc <= line;) {
            int i = flag ? dr : tr;
            int j = flag ? dc : tc;
            for (;;) {
                res.push_back(mat[i][j]);
                if (flag) {
                    i--, j++;
                    if (i < tr && j > tc) {
                        break;
                    }
                } else {
                    i++, j--;
                    if (i > dr && j < dc) {
                        break;
                    }
                }
            }
            if (tc == line) {
                tr++;
            } else {
                tc++;
            }
            if (dr == row) {
                dc++;
            } else {
                dr++;
            }
            flag = !flag;
        }
        return res;
    }
};

void print_vec(const std::vector<int>& res) {
    for (const auto& x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = s.findDiagonalOrder(mat);
    print_vec(res);
    return 0;
}
