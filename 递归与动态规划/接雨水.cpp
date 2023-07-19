#include <vector>
#include <iostream>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        std::vector<int> left_high(height.size(), 0);
        std::vector<int> right_high(height.size(), 0);
        for (int i = 1; i < height.size(); i++) {
            left_high[i] = std::max(height[i-1], left_high[i-1]);
        }
        for (int i = height.size()-2; i >= 0; i--) {
            right_high[i] = std::max(height[i+1], right_high[i+1]);
        }
        int res = 0;
        for (int i = 1; i < height.size()-1; i++) {
            int min = std::min(left_high[i], right_high[i]);
            if (height[i] >= min) {
                continue;
            } else {
                res += min - height[i];
            }
        }
        return res;
    }
};

int main() {
    // std::vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> height{4,2,0,3,2,5};
    Solution s;
    auto res = s.trap(height);
    std::cout << res << std::endl;
    return 0;
}