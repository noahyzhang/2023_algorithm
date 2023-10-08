#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int countSubstrings(const std::string& str) {
        if (str.empty()) {
            return 0;
        }
        std::string wrap_str;
        wrap_str.resize(str.size()*2+1);
        int index = 0;
        for (int i = 0; i < str.size()*2+1; i++) {
            wrap_str[i] = (i & 0x01) == 0 ? '#' : str[index++];
        }
        std::vector<int> pArr(wrap_str.size(), 0);
        int R = -1;
        int C = -1;
        int len = 0;
        for (int i = 0; i < wrap_str.size(); i++) {
            // i > R 说明 i 在 L..R 范围外。还需要往外扩
            // i <= R 说明 i 在 L..R 范围内。处于边界上时需要往外扩，
            pArr[i] = i > R ? 1 : std::min(pArr[2*C-i], R-i);
            while (i+pArr[i] < wrap_str.size() && i - pArr[i] > -1) {
                if (wrap_str[i+pArr[i]] == wrap_str[i-pArr[i]]) {
                    pArr[i]++;
                } else {
                    break;
                }
            }
            if (i+pArr[i] > R) {
                R = i+pArr[i];
                C = i;
            }
            len += (pArr[i]/2);
        }
        return len;
    }
};

int main() {
    Solution s;
    int res = s.countSubstrings("abc");
    std::cout << res << std::endl;
    return 0;
}
