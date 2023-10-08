#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }
        // 找到第一个 "nums[index-1] > nums[index]" 的位置
        int index = nums.size()-1;
        while (index >= 1 && nums[index] <= nums[index-1]) {
            index--;
        }
        if (index >= 1) {
            int pos = nums.size()-1;
            while (pos >= index && nums[pos] <= nums[index-1]) {
                pos--;
            }
            std::swap(nums[pos], nums[index-1]);
        }
        std::reverse(nums.begin()+index, nums.end());
        return;
    }
};

int main() {
    std::vector<int> arr{1, 2, 3};
    Solution s;
    s.nextPermutation(arr);
    for (const auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
