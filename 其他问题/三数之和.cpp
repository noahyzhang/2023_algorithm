#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.empty()) {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first-1]) {
                continue;
            }
            int target = -nums[first];
            int third = nums.size()-1;
            for (int second = first+1; second < nums.size(); second++) {
                if (second > first+1 && nums[second] == nums[second-1]) {
                    continue;
                }
                // 需要保证 second 在 third 的左边
                while (second < third && nums[second] + nums[third] > target) {
                    third--;
                }
                if (second >= third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    res.emplace_back(std::vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};

int main() {
    // std::vector<int> nums{-1,0,1,2,-1,-4};
    std::vector<int> nums{0, 0, 0, 0};
    Solution s;
    auto arrs = s.threeSum(nums);
    for (const auto& arr : arrs) {
        for (const auto& x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
