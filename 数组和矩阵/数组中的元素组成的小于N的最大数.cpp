

// 数组A中给定可以使用的 1~9 的数，返回由 A 数组中的元素组成的小于 n 的最大数。
// 例如 A={1, 2, 4, 9}，x=2533，返回 2499

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

class Solution {
public:
    std::string get_max_less_num(std::vector<int> nums, int N) {
        std::sort(nums.begin(), nums.end());
        std::string max_below = get_max_below(nums, N);
        std::string sb;
        bool flag = false;
        for (int i = 0; i < max_below.size(); i++) {
            char ch = max_below[i];
            if (flag) {
                sb.push_back(nums[nums.size()-1]+'0');
            } else {
                int index = get_index(nums, max_below, i);
                sb.push_back(nums[index]+'0');
                if (nums[index] < ch-'0') {
                    flag = true;
                }
            }
        }
        return sb;
    }

    std::string get_max_below(const std::vector<int>& nums, int N) {
        std::string str = std::to_string(N);
        int min = nums[0];
        bool flag = check(str, min);
        int num = flag ? (N-1) : static_cast<int>(std::pow(10, str.size()-1) - 1);
        return std::to_string(num);
    }

private:
    bool check(const std::string& str, int min_val) {
        if (str.empty()) {
            return true;
        }
        char ch = str[0];
        if (ch - '0' > min_val) {
            return true;
        } else if (ch - '0' < min_val) {
            return false;
        } else {
            return check(str.substr(1), min_val);
        }
    }

    int get_index(const std::vector<int>& nums, const std::string& max_below, int index) {
        int cur_num = max_below[index] - '0';
        if (index < max_below.size()-1) {
            int next_num = max_below[index+1] - '0';
            // 下一位不能小于等于 nums[0]，否则就要选小于 cur_num 的数
            if (next_num <= nums[0]) {
                cur_num -= 1;
            }
        }
        // cur_num 处理完后，找到小于等于 cur_num 的数
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == cur_num) {
                left = mid+1;
            } else if (nums[mid] < cur_num) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};

int main() {
    // std::vector<int> nums{2, 3, 9};
    // int N = 24399;
    // std::vector<int> nums{1, 2, 4, 9};
    std::vector<int> nums{5, 3, 4, 9};
    int N = 2533;
    Solution s;
    // std::cout << s.get_max_below(nums, N) << std::endl;
    std::cout << s.get_max_less_num(nums, N) << std::endl;
    return 0;
}
