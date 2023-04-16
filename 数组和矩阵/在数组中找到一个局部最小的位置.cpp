#include <vector>
#include <iostream>

class Solution {
public:
    int get_less_index(const std::vector<int>& arr) {
        // arr 为空
        if (arr.empty()) {
            return -1;
        }
        // arr 只有一个值. 判断最左边或者最右边，如果有局部最小，直接返回即可
        if (arr.size() == 1 || arr[0] < arr[1]) {
            return 0;
        }
        int count = arr.size();
        if (arr[count-2] > arr[count-1]) {
            return count-1;
        }
        // 二分查找
        int left = 1, right = count-2;
        for (; left < right;) {
            int mid = left + (right-left) / 2;
            if (mid-1 >= 0 && arr[mid] > arr[mid-1]) {
                right = mid - 1;
            } else if (mid+1 <= count && arr[mid] > arr[mid+1]) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{5, 4, 0, 9, 21, 3, 10};
    auto res = s.get_less_index(arr);
    std::cout << res << std::endl;
    return 0;
}