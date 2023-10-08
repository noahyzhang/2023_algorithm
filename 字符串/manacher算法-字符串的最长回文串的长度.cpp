
/**
 * Manacher 算法
 * 先给这个字符串中所有位置插入一个虚轴，也就是一个字符，比如 #
 * 
 * 有这么几个变量
 * 最长回文半径数组 pArr、最有可以扩到的位置 R、当前回文串的中心位置 C
 * 
 * 假设遍历到 i 位置
 * 第一种情况，无脑扩，也就是此时 pArr 中没有对应点。也就是 i 在 R 外
 * 第二张情况，现在 i 在 R 内，那么 i 一定会关于 C 对应一个 i' 。此时，分三种小情况
 *  1. i' 所代表的回文串是 L...R 范围内。这种情况下，那么 i 代表的回文串也一定在 R 范围内
 *  2. i' 所代表的回文串在 L...R 范围外，这种情况下，那么 i 代表的回文串长度一定刚好在 R 范围上
 *  3. i' 所代表的回文串在 L...R 边界上，这种情况下，那么 i 代表的回文串需要往外扩
 * 在遍历过程中，记录每个回文串的半径长度
 * 
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int get_max_palindrome_len(const std::string& str) {
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
        int max = 0;
        for (int i = 0; i < wrap_str.size(); i++) {
            // i > R 说明 i 在 L..R 范围外。还需要往外扩
            // i <= R 说明 i 在 L..R 范围内。处于边界上时需要往外扩，
            pArr[i] = i > R ? 1 : std::min((2*C-i >= 0 ? pArr[2*C-i] : R-i), R-i);
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
            max = std::max(max, pArr[i]);
        }
        return max-1;
    }
};

class Solution2 {
public:
    std::string get_max_palindrome_str(const std::string& str) {
        if (str.empty()) {
            return "";
        }
        std::string wrap_str;
        wrap_str.resize(str.size()*2+1);
        int index = 0;
        for (int i = 0; i < wrap_str.size(); i++) {
            // 注意，& 和 == 运算符的优先级
            wrap_str[i] = (i & 0x01) == 0 ? '#' : str[index++];
        }
        std::vector<int> pArr(wrap_str.size(), 0);
        int R = -1;
        int C = -1;
        for (int i = 0; i < wrap_str.size(); i++) {
            // i > R 说明 i 在 L..R 范围外。还需要往外扩
            // i <= R 说明 i 在 L..R 范围内。处于边界上时需要往外扩，
            // 注意：2*C-i 可能被 leetcode 认为有可能小于 0，导致代码检测失败。这里给判断一下
            pArr[i] = i > R ? 1 : std::min((2*C-i >= 0 ? pArr[2*C-i] : R-i), R-i);
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
        }
        int max_radii = 0;
        int pos = 0;
        for (int i = 0; i < pArr.size(); i++) {
            if (pArr[i] > max_radii) {
                max_radii = pArr[i];
                pos = i;
            }
        }
        // 奇回文：回文半径是偶数。中心点是实轴，就是非 # 字符。它的边界肯定是我们添加的 # 字符
        // 偶回文：回文半径是奇数。中心点是虚轴，就是我们添加的 # 字符。它的边界肯定也是我们添加的 # 字符
        // 但是无论是奇回文，还是偶回文。他们的边界一定是我们添加的 # 字符，因此我们要跳过这个 # 字符
        std::string res;
        for (int i = pos-max_radii+1+1; i <= pos+max_radii-1-1; i+=2) {
            res.push_back(wrap_str[i]);
        }
        return res;
    }
};

int main() {
    std::string str("babad");
    Solution2 s;
    auto res = s.get_max_palindrome_str(str);
    std::cout << res << std::endl;
    return 0;
}
