
// 找出数组中重复的数字。
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3 

#include <vector>

class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int k = nums[i];
            if(k < 0) k += n;
            if(nums[k] < 0) return k;
            nums[k] -= n;
        }
        
        return -1;
    }
};

