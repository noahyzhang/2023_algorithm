#include <vector>
#include <iostream>

class Solution {
public:
    void modify(std::vector<int>& vec) {
        int even = 0, odd = 1;
        int count = vec.size()-1;
        for (; even <= count && odd <= count;) {
            if (vec[count] % 2 == 0) {
                if (vec[even] % 2 != 0) {
                    std::swap(vec[even], vec[count]);
                }
                even += 2;
            } else {
                if (vec[odd] % 2 == 0) {
                    std::swap(vec[odd], vec[count]);
                }
                odd += 2;
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
    std::vector<int> arr{1,2,3,4,5,6};
    s.modify(arr);
    print_arr(arr);
    return 0;
}