#include <vector>
#include <algorithm>
#include <iostream>

struct Solution {
public:
    int get_pos(const std::string& str1, const std::string& str2) {
        if (str1.empty() || str2.empty() || str1.size() < str2.size()) {
            return -1;
        }
        std::vector<int> next_arr = get_next_arr(str2);
        int i_1 = 0;
        int i_2 = 0;
        while (i_1 < str1.size() && i_2 < str2.size()) {
            if (str1[i_1] == str2[i_2]) {
                i_1++;
                i_2++;
            } else if (i_2 > 0) {
                i_2 = next_arr[i_2];
            } else {
                i_1++;
            }
        }
        return i_2 == str2.size() ? (i_1 - i_2) : -1;
    }

private:
    std::vector<int> get_next_arr(const std::string& str) {
        if (str.size() == 1) {
            return std::vector<int>{-1};
        }
        std::vector<int> vec(str.size(), 0);
        vec[0] = -1;
        vec[1] = 0;
        int i = 2;
        int cn = 0;
        while (i < vec.size()) {
            if (str[i-1] == str[cn]) {
                vec[i++] = ++cn;
            } else if (cn > 0) {
                cn = vec[cn];
            } else {
                vec[i++] = 0;
            }
        }
        return vec;
    }
};

int main() {
    Solution s;
    auto res = s.get_pos("sadbutsad", "sad");
    std::cout << res << std::endl;
    return 0;
}
