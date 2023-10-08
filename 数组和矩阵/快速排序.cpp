#include <time.h>
#include <unistd.h>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        sort_array_sub(nums, 0, nums.size()-1);
        return nums;
    }

private:
    void sort_array_sub(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pos = (rand() % (right-left+1)) + left;
        std::swap(nums[left], nums[pos]);
        int value = nums[left];

        int less = left;
        int more = right + 1;
        for (int j = left+1; j < more;) {
            if (nums[j] < value) {
                less++;
                std::swap(nums[less], nums[j]);
                j++;
            } else if (nums[j] == value) {
                j++;
            } else {
                more--;
                std::swap(nums[more], nums[j]);
            }
        }
        std::swap(nums[less], nums[left]);

        sort_array_sub(nums, left, less-1);
        sort_array_sub(nums, more, right);
    }
};

int main() {
    srand(time(nullptr));
    std::vector<int> nums{5,1,1,2,0,0};
    Solution s;
    auto res = s.sortArray(nums);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
