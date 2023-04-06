#include <vector>
#include <iostream>

class Solution {
public:
    int findUnsortedSubarray(const std::vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) {
            return 0;
        }
        int count = nums.size();
        int left = -1;
        int min = count-1;
        for (int i = count-2; i >= 0; --i) {
            if (nums[i] > nums[min]) {
                left = i;
            } else {
                min = i;
            }
        }
        if (left == -1) {
            return 0;
        }
        int right = 0;
        int max = 0;
        for (int i = 1; i < count; ++i) {
            if (nums[i] < nums[max]) {
                right = i;
            } else {
                max = i;
            }
        }
        return right - left + 1;
    }
};

int main() {
    Solution s;
    // std::vector<int> arr{1, 5, 3, 4, 2, 6, 7};
    std::vector<int> arr{2, 6, 4, 8, 10, 9, 15};
    // std::vector<int> arr{2, 1};
    auto res = s.findUnsortedSubarray(arr);
    std::cout << res << std::endl;
    return 0;
}
