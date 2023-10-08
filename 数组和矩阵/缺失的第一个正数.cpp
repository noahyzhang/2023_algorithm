#include <vector>
#include <iostream>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        for (auto& x : nums) {
            if (x <= 0) {
                x = n+1;
            }
        }
        for (int i = 0; i < n; i++) {
            int num = std::abs(nums[i]);
            if (num <= n) {
                nums[num-1] = -std::abs(nums[num-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }
        return n+1;
    }
};

