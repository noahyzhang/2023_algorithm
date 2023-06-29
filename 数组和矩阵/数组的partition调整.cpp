#include <vector>
#include <iostream>

class Solution {
public:
    void partition_sort(std::vector<int>& arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        int u = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[u] != arr[i]) {
                if (u+1 != i) {
                    std::swap(arr[u+1], arr[i]);
                }
                u++;
            }
        }
    }
};

void print_arr(const std::vector<int>& arr) {
    for (const auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    std::vector<int> arr{1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9};
    s.partition_sort(arr);
    print_arr(arr);
    return 0;
}
