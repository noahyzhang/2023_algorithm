#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // 简单的 twoSum 问题
    std::vector<int> twoSum(std::vector<int> nums, int target) {
        if (nums.size() < 2) {
            return std::vector<int>();
        }
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return std::vector<int>{nums[left], nums[right]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return std::vector<int>();
    }

    // twoSum 问题升级，希望返回所有元素对，并且不能出现重复
    std::vector<std::pair<int, int>> twoSum2(std::vector<int> nums, int target) {
        if (nums.size() < 2) {
            return std::vector<std::pair<int, int>>();
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::pair<int, int>> res;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int left_val = nums[left];
            int right_val = nums[right];
            int sum = left_val + right_val;
            if (sum == target) {
                res.emplace_back(std::pair<int, int>{left_val, right_val});
                while (left < right && nums[left] == left_val) left++;
                while (left < right && nums[right] == right_val) right--;
            } else if (sum < target) {
                while (left < right && nums[left] == left_val) left++;
            } else {
                while (left < right && nums[right] == right_val) right--;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums, long int target) {
        if (nums.size() < 3) {
            return std::vector<std::vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size()-2; i++) {
            auto tuples = twoSum(nums, i+1, target-nums[i]);
            for (auto& x : tuples) {
                x.emplace_back(nums[i]);
                res.emplace_back(x);
            }
            while (i < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }

private:
    std::vector<std::vector<int>> twoSum(const std::vector<int>& nums, int start, long int target) {
        if (nums.size() < 2) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> res;
        int left = start, right = nums.size()-1;
        while (left < right) {
            int left_val = nums[left];
            int right_val = nums[right];
            int sum = left_val + right_val;
            if (sum == target) {
                res.push_back(std::vector<int>{left_val, right_val});
                while (left < right && nums[left] == left_val) left++;
                while (left < right && nums[right] == right_val) right--;
            } else if (sum < target) {
                while (left < right && nums[left] == left_val) left++;
            } else {
                while (left < right && nums[right] == right_val) right--;
            }
        }
        return res;
    }
};

class Solution3 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> nums, long int target) {
        if (nums.size() < 4) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; i++) {
            // 注意这里 target-nums[i] 有可能减越界，所以使用 long int
            auto triples = threeSum(nums, i+1, target-nums[i]);
            for (auto& x : triples) {
                x.emplace_back(nums[i]);
                res.emplace_back(x);
            }
            while (i < nums.size()-3 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }

private:
    std::vector<std::vector<int>> threeSum(std::vector<int> nums, int start, long int target) {
        if (nums.size() < 3) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> res;
        for (int i = start; i < nums.size()-2; i++) {
            auto tuples = twoSum(nums, i+1, target-nums[i]);
            for (auto& x : tuples) {
                x.emplace_back(nums[i]);
                res.emplace_back(x);
            }
            while (i < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }

    std::vector<std::vector<int>> twoSum(const std::vector<int>& nums, int start, long int target) {
        if (nums.size() < 2) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> res;
        int left = start, right = nums.size()-1;
        while (left < right) {
            int left_val = nums[left];
            int right_val = nums[right];
            int sum = left_val + right_val;
            if (sum == target) {
                res.push_back(std::vector<int>{left_val, right_val});
                while (left < right && nums[left] == left_val) left++;
                while (left < right && nums[right] == right_val) right--;
            } else if (sum < target) {
                while (left < right && nums[left] == left_val) left++;
            } else {
                while (left < right && nums[right] == right_val) right--;
            }
        }
        return res;
    }
};


int main() {
    // std::vector<int> nums{1, 3, 5, 6};
    // std::vector<int> nums{1,1,1,2,2,3,3};
    // std::vector<int> nums{1,0,-1,0,-2,2};
    // std::vector<int> nums{2,2,2,2,2};
    std::vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;

    Solution3 s3;
    auto res = s3.fourSum(nums, target);
    for (const auto& x : res) {
        for (const auto& y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }

    // Solution2 s2;
    // auto res = s2.threeSum(nums, target);
    // for (const auto& x : res) {
    //     for (const auto& y : x) {
    //         std::cout << y << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // Solution s;
    // auto res = s.twoSum(nums, target);
    // for (const auto& x : res) {
    //     std::cout << x << " ";
    // }
    // auto res = s.twoSum2(nums, target);
    // for (const auto& x : res) {
    //     std::cout << x.first << " " << x.second << std::endl;
    // }
    std::cout << std::endl;
    return 0;
}