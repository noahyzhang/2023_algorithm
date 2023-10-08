
#include <string>
#include <iostream>

class Solution {
public:
    std::string delete_n_numbers(std::string& str, int n) {
        bool flag = false;
        int start_pos = 0;
        for (int i = 0; i < n; i++) {
            flag = false;
            for (int j = start_pos; j < str.size()-1; j++) {
                if (str[j] > str[j+1]) {
                    str.erase(j, 1);
                    flag = true;
                    start_pos = j == 0 ? 0 : j-1;
                    break;
                }
            }
            // 如果所有数都递增，删除最后 i 个数字后直接返回
            if (flag == false) {
                str.erase(str.end()-i, str.end());
                break;
            }
        }
        return str;
    }
};

int main() {
    std::string str = "324682385";
    // std::string str = "1221";
    int n = 3;
    Solution s;
    auto res = s.delete_n_numbers(str, n);
    std::cout << res << std::endl;
    return 0;
}