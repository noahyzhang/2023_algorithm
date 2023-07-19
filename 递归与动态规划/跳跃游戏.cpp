#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // 无法处理不能跳到的情况
    int jump(const std::vector<int>& nums) {
        size_t jump = 0, cur = 0, next = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (cur < i) {
                jump++;
                cur = next;
            }
            next = std::max(next, i+nums[i]);
        }
        return jump;
    }

    bool canJump(const std::vector<int>& nums) {
        size_t jump = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > jump) return false;
            jump = std::max(jump, i+nums[i]);
        }
        return true;
    }
};

int main() {
    Solution s;
    int res = s.jump({3, 2, 1, 0, 4});
    std::cout << res << std::endl;
    return 0;
}
