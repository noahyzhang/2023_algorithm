#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void print_vec(const std::vector<int>& vec) {
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int max_res = 0;
        std::vector<int> height_arr(matrix.back().size(), 0);
        for (const auto& row : matrix) {
            for (size_t i = 0; i < row.size(); ++i) {
                height_arr[i] = row[i] == '0' ? 0 : ++height_arr[i];
            }
            max_res = std::max(max_res, get_max_matrix_area(height_arr));
        }
        return max_res;
    }

private:
    int get_max_matrix_area(std::vector<int>& height_arr) {
        std::stack<int> st;
        int j = 0, k = 0;
        int max_res = 0;
        for (size_t i = 0; i < height_arr.size(); ++i) {
            if (st.empty()) {
                st.push(i);
            } else {
                j = st.top();
                if (height_arr[i] > height_arr[j]) {
                    st.push(i);
                } else {
                    while (!st.empty() && height_arr[i] <= height_arr[st.top()]) {
                        j = st.top();
                        st.pop();
                        k = st.empty() ? -1 : st.top();
                        max_res = std::max(max_res, static_cast<int>(((i-k-1) * height_arr[j])));
                    }
                    st.push(i);
                }
            }
        }
        while (!st.empty()) {
            j = st.top();
            st.pop();
            k = st.empty() ? -1 : st.top();
            max_res = std::max(max_res, static_cast<int>((height_arr.size()-k-1) * height_arr[j]));
        }
        return max_res;
    }
};

int main() {
    // std::vector<std::string> matrix = {"10100", "10111", "11111", "10010"};
    // std::vector<std::string> matrix = {"1011", "1111", "1110"};
    std::vector<std::string> matrix;
    Solution s;
    auto res = s.maximalRectangle(matrix);
    std::cout << res << std::endl;
    return 0;
}
