#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int max_points(const std::vector<std::vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (res >= n-1 || res > n/2) {
                break;
            }
            std::unordered_map<int, int> mp;
            for (int j = i+1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcd_xy = gcd(std::abs(x), std::abs(y));
                    x /= gcd_xy;
                    y /= gcd_xy;
                }
                mp[y + x * 20001]++;
            }
            int max_n = 0;
            for (const auto& x : mp) {
                max_n = std::max(max_n, x.second+1);
            }
            res = std::max(res, max_n);
        }
        return res;
    }

private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};

int main() {
    std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    Solution s;
    auto res = s.max_points(points);
    std::cout << res << std::endl;
    return 0;
}
