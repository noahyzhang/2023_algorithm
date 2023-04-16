#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> get_product(const std::vector<int>& arr) {
        if (arr.size() < 2) {
            return arr;
        }
        int count = arr.size();
        std::vector<int> res(count, 0);
        std::vector<int> left_product(count, 0);
        std::vector<int> right_product(count, 0);
        left_product[1] = arr[0];
        for (int i = 2; i < count; ++i) {
            left_product[i] = left_product[i-1] * arr[i-1];
        }
        right_product[count-2] = arr[count-1];
        for (int i = count-3; i >= 0; --i) {
            right_product[i] = right_product[i+1] * arr[i+1];
        }
        res[0] = right_product[0];
        res[count-1] = left_product[count-1];
        for (int i = 1; i < count-1; ++i) {
            res[i] = left_product[i] * right_product[i];
        }
        return res;
    }

    std::vector<int> get_product2(const std::vector<int>& arr) {
        if (arr.empty() || arr.size() < 2) {
            return std::vector<int>();
        }
        int count = 0;
        int all = 1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != 0) {
                all *= arr[i];
            } else {
                count++;
            }
        }
        std::vector<int> res(arr.size(), 0);
        if (count == 0) {
            for (int i = 0; i < arr.size(); ++i) {
                res[i] = all / arr[i];
            }
        }
        if (count == 1) {
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] == 0) {
                    res[i] = all;
                }
            }
        }
        return res;
    }

    std::vector<int> get_product3(const std::vector<int>& arr) {
        if (arr.empty() || arr.size() < 2) {
            return std::vector<int>();
        }
        std::vector<int> res(arr.size(), 0);
        res[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            res[i] = res[i-1] * arr[i];
        }
        int tmp = 1;
        for (int i = arr.size() - 1; i > 0; --i) {
            res[i] = res[i-1] * tmp;
            tmp *= arr[i];
        }
        res[0] = tmp;
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{2, 3, 1, 4};
    auto res = s.get_product3(arr);
    for (const auto& x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}