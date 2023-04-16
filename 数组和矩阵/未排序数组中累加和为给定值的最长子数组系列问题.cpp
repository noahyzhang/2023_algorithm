
/**
 * 未排序数组中累加和为给定值的最长子数组系列问题
 * 1. 给定一个无序数组 arr，其中元素可正、可负、可 0。给定一个整数 k，求 arr 所有的子数组中累加和为 k 的最长子数组长度
 * 2. 给定一个无序数组 arr，其中元素可正、可负、可 0。求 arr 所有的子数组中正数与负数个数相等的最长子数组长度
 * 3. 给定一个无序数组 arr，其中元素只是 1 和 0。求 arr 所有子数组中 0 和 1 个数相等的最长子数组长度
 * 
 * 问题 2 和问题 3 都可以转换为问题 1
 * 问题 2 可以把数组中正数、负数转换为 1 和 -1，然后求累加和为 0 的最长子数组长度
 * 问题 3 可以把数组中的 0 转换为 -1，然后求累加和为 0 的最长子数组长度
 */

/**
 * s(i) = arr[0 ... i]
 * s(j) = arr[0 ... j] , 假定 j < i
 * arr[j+1 ... i] = s(i) - s(j)
 * arr[j ... i] = s(i) - s(j-1)
 * 那么假定 s(i) 为 sum，sum-k 为 s(j); 那么 k = s(i) - s(j) = arr[j+1 ... i]
 * 其中 sum-k 就是我们 map 中的 value，存储的是位置，以 j 来标识
 * 我们每次判断 map 中是否存在 sum-k，即可确定数组中是否有累加和为 k 的子数组
 * sum - (sum-k) = k  ===> arr[j+1 ... i]
 * 
 * 我们的子数组是从 arr[j+1 ... i] 因此会忽略到 arr[0]
 * 所以先给 map 填充 (0, -1)，表示 sum 值为 0 时，j 的位置
 */ 

#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int get_max_subarr(const std::vector<int>& arr, int k) {
        if (arr.empty()) {
            return 0;
        }
        // 表示当前范围内数组的累加和
        int sum = 0;
        // map 的 key 为 sum 值，value 表示第一次出现 sum 值的位置
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        int len = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            auto iter = mp.find(sum-k);
            if (iter != mp.end()) {
                len = std::max(len, i - iter->second);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    std::vector<int> arr{1, 2, 3};
    auto res = s.get_max_subarr(arr, 3);
    std::cout << res << std::endl;
    return res;
}
