// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

// P   A   H   N
// A P L S I I G
// Y   I   R

// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int num_rows) {
        if (s.empty() || num_rows <= 1) return s;
        int row = num_rows;
        int t = 2*row-2;
        int n = s.size();
        int line = (n + t - 1) / t * (row-1);
        std::vector<std::vector<char>> vec(row, std::vector<char>(line, 0));
        int vec_row = -1, vec_line = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (flag == true) {
                vec_row++;
                vec[vec_row][vec_line] = s[i];
                if (vec_row == row-1) {
                    flag = false;
                }
            } else {
                vec_row--;
                vec_line++;
                vec[vec_row][vec_line] = s[i];
                if (vec_row == 0) {
                    flag = true;
                }
            }
        }
        print_vec(vec);
        std::string res;
        res.reserve(n);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < line; j++) {
                if (vec[i][j] != 0) {
                    res.push_back(vec[i][j]);
                }
            }
        }
        return res;
    }

private:
    void print_vec(const std::vector<std::vector<char>>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[0].size(); j++) {
                std::cout << vec[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

class Solution2 {
public:
    std::string convert(std::string s, int num_rows) {
        if (s.empty() || num_rows <= 1) {
            return s;
        }
        std::vector<std::string> vec(num_rows);
        int vec_row = -1;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (flag == true) {
                vec_row++;
                vec[vec_row].push_back(s[i]);
                if (vec_row == num_rows-1) {
                    flag = false;
                }
            } else {
                vec_row--;
                vec[vec_row].push_back(s[i]);
                if (vec_row == 0) {
                    flag = true;
                }
            }
        }
        std::string res;
        res.reserve(s.size());
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
            res.append(vec[i]);
        }
        return res;
    }
};

class Solution3 {
public:
    std::string convert(const std::string& s, int numRows) {
        if (s.empty() || numRows <= 1 || numRows >= s.size()) {
            return s;
        }
        int n = s.size();
        int r = numRows;
        int t = r*2-2;
        std::string res;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j+i < n; j += t) {
                res.push_back(s[j+i]);
                if (0 < i && i < r-1 && j+t-i < n) {
                    res.push_back(s[j+t-i]);
                }
            }
        }
        return res;
    }
};

int main() {
    std::string str = "PAYPALISHIRING";
    int num_rows = 3;
    Solution3 s;
    auto res = s.convert(str, num_rows);
    std::cout << res << std::endl;
    return 0;
}
