#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void sort_01(std::vector<int>& arr) {
        int i = 0;
        for (; i < arr.size();) {
            if (arr[i] == i+1) {
                i++;
            } else {
                std::swap(arr[i], arr[arr[i]-1]);
            }
        }
    }
};

void print_arr(const std::vector<int>& arr) {
    for (const auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    std::vector<int> arr{2,1,4,5,3};
    s.sort_01(arr);
    print_arr(arr);
    return 0;
}
