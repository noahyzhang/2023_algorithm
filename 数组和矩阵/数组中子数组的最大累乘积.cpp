#include <vector>
#include <iostream>

class Solution {
public:
    double get_max_product(const std::vector<double>& arr) {
        if (arr.empty()) {
            return 0;
        }
        double max = arr[0];
        double min = arr[0];
        double res = max;
        for (int i = 1; i < arr.size(); ++i) {
            double first = max*arr[i];
            double second = min*arr[i];
            max = std::max(std::max(first, second), arr[i]);
            min = std::min(std::min(first, second), arr[i]);
            res = std::max(max, res);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<double> arr{2.5, 4, 0, 3, 0.5, 8, 01};
    auto res = s.get_max_product(arr);
    std::cout << res << std::endl;
    return 0;
}
