#include <vector>
#include <iostream>

class Solution {
public:
    int get_max_length(const std::vector<int>& arr, int k) {
        if (arr.empty()) {
            return 0;
        }
        int left = 0, right = 0;
        int sum = arr[0];
        int len = 0;
        for (; right < arr.size();) {
            if (sum == k) {
                len = std::max(len, right-left+1);
                sum -= arr[left++];
            } else if (sum < k) {
                right++;
                if (right < arr.size()) {
                    sum += arr[right];
                } else {
                    break;
                }
            } else {
                sum -= arr[left++];
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{1, 9, 1, 2, 3};
    int res = s.get_max_length(arr, 5);
    std::cout << res << std::endl;
    return 0;
}
