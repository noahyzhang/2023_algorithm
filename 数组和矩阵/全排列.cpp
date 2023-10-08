#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.empty()) {
            return res;
        }
        recursion(res, nums, 0, nums.size()-1);
        return res;
    }

private:
    void recursion(std::vector<std::vector<int>>& res, std::vector<int>& nums, int left, int right) {
        if (left == right) {
            res.push_back(nums);
        }
        for (int i = left; i <= right; i++) {
            std::swap(nums[i], nums[left]);
            recursion(res, nums, left+1, right);
            std::swap(nums[i], nums[left]);
        }
    }
};

int main() {
    std::vector<int> nums{1, 2, 3};
    Solution s;
    auto res = s.permute(nums);
    for (const auto& arr : res) {
        for (const auto& x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

