#include <vector>
#include <iostream>

class Solution {
public:
    // 不重复打印排序数组中相加和为给定值的所有二元组
    void print_unique_pair(const std::vector<int>& arr, int k) {
        if (arr.empty()) {
            return;
        }
        std::vector<std::pair<int, int>> res;
        int left = 0, right = arr.size()-1;
        for (; left < right;) {
            int val = arr[left] + arr[right];
            if (val > k) {
                right--;
            } else if (val < k) {
                left++;
            } else {
                if (left == 0 || arr[left] != arr[left-1]) {
                    res.emplace_back(arr[left], arr[right]);
                }
                left++, right--;
            }
        }
        for (const auto& x : res) {
            std::cout << x.first << " " << x.second << std::endl;
        }
    }

    // 不重复打印排序数组中相加和为给定值的所有三元组
    void print_unique_triple(const std::vector<int>& arr, int k) {
        if (arr.empty()) {
            return;
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < arr.size(); ++i) {
            if (i != 0 && arr[i] == arr[i-1]) {
                continue;
            }
            int second = i+1, third = arr.size()-1;
            for (; second < third;) {
                int val = arr[i] + arr[second] + arr[third];
                if (val > k) {
                    third--;
                } else if (val < k) {
                    second++;
                } else {
                    if (arr[second] != arr[second-1]) {
                        res.push_back({arr[i], arr[second], arr[third]});
                    }
                    second++, third--;
                }
            }
        }
        for (const auto& x : res) {
            std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
        }
    }
};

int main() {
    Solution s;
    std::vector<int> arr{-8, -4, -3, 0, 1, 1, 2, 4, 5, 8, 9};
    // s.print_unique_pair(arr, 10);
    s.print_unique_triple(arr, 10);
    return 0;
}
