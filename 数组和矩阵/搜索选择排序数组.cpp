
// 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
// 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. 

#include <vector>
#include <iostream>

// 这种情况中，数组中没有重复元素
class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // [left, mid] 是升序的
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};

// 如果数组中有重复元素
// 这个时候，对于 nums[left] == nums[mid] == nums[right] 的情况，我们应该将将 left++，right--
class Solution2 {
public:
    int search(const std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> nums{2,5,6,0,0,1,2};
    Solution2 s;
    auto res = s.search(nums, 0);
    std::cout << res << std::endl;
    return 0;
}
