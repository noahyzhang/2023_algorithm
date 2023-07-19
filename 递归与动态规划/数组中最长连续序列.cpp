#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int get_longest_consecutive(const std::vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        // 注意，这里必须为 1，因为数组中如果有值，那么必然最小的子序列长度为 1
        int res = 1;
        std::unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = 1;
                if (mp.find(arr[i]-1) != mp.end()) {
                    res = std::max(res, merge(mp, arr[i]-1, arr[i]));
                }
                if (mp.find(arr[i]+1) != mp.end()) {
                    res = std::max(res, merge(mp, arr[i], arr[i]+1));
                }
            }
        }
        return res;
    }

private:
    int merge(std::unordered_map<int, int>& mp, int less, int more) {
        int left = less - mp.at(less) + 1;
        int right = more + mp.at(more) - 1;
        int len = right - left + 1;
        mp[left] = len;
        mp[right] = len;
        return len;
    }
};

int main() {
    std::vector<int> arr{100, 4, 200, 1, 3, 2};
    Solution s;
    int res = s.get_longest_consecutive(arr);
    std::cout << res << std::endl;
    return 0;
}
