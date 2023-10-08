#include <vector>
#include <iostream>

struct Elem {
    int max{INT32_MIN};
    int min{INT32_MAX};
    bool is_empty{true};
};

class Solution {
public:
    int get_max_gap(const std::vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int max = INT32_MIN;
        int min = INT32_MAX;
        for (int i = 0; i < arr.size(); i++) {
            max = std::max(max, arr[i]);
            min = std::min(min, arr[i]);
        }
        if (min == max) {
            return 0;
        }
        std::vector<Elem> nums;
        nums.resize(arr.size()+1);
        for (int i = 0; i < arr.size(); i++) {
            int pos = (arr[i]-min) * arr.size() / (max-min);
            nums[pos].max = std::max(nums[pos].max, arr[i]);
            nums[pos].min = std::min(nums[pos].min, arr[i]);
            nums[pos].is_empty = false;
        }
        int res = INT32_MIN;
        for (int i = 0, j = 1; i < nums.size()-1 && j < nums.size();) {
            if (nums[i].is_empty == true) {
                i++;
                continue;
            }
            if (nums[j].is_empty == true) {
                j++;
                continue;
            }
            res = std::max(res, nums[j].min - nums[i].max);
            i++;
            j++;
        }
        return res;
    }
};

int main() {
    std::vector<int> arr{1,3,6,7};
    Solution s;
    auto res = s.get_max_gap(arr);
    std::cout << res << std::endl;
    return 0;
}
