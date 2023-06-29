#include <vector>
#include <iostream>

/**
 * 1. 先求出数组中的最大值 min、最小值 max
 * 2. 利用桶排序的思路，我们设定桶的个数为 N+1（N 为数组的长度）
 * 3. 然后每个桶中存储的区间范围为：(max-min) / N，N+1 号桶只存储 max（max 可能会有多个）
 * 4. 比如，一个数组有 10 个元素，最大值为 110，最小值为 10。1 号桶存储 [10, 20), 10 号桶存储 [100, 110), 11 号桶只存储 110 这个数
 * 5. 那么任意一个元素 num 应该存储到那个桶呢？答案是 (num-min) / ( (max-min)/N ) ==> (num-min)/N*(max-min)。这里是按照桶号从 0 开始计算的
 * 6. 那么有 N 个元素，但是我们有 N+1 个桶。因此我们的桶中肯定会有 1 个以上的空桶
 * 7. 而且我们发现一个桶中的元素的相邻数最大差值，肯定小于区间范围。但是相邻桶之间的元素的最大差值肯定大于区间范围
 * 8. 至此，我们可以得出结论了，我们找到空桶之前的一个非空桶的最大值，和空桶之后一个非空桶的最小值，两个数的差值即为相邻数的最大差值
 * 9. 注意，可能会存在多个空桶，我们要注意此点
 * 
 * 注意：(num - min) * count / (max - min); 和  (num-min) / ( (max-min) / count ) 是有区别的
 * 如果数组中最大值也小于 count，那么 (max-min)/count 永远等于 0 了，无法给元素分桶了
 * 
 */ 

class Solution {
public:
    int get_max_gap(const std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return 0;
        }
        int max = INT32_MIN, min = INT32_MAX;
        for (const auto& x : nums) {
            if (x > max) {
                max = std::max(max, x);
            }
            if (x < min) {
                min = std::min(min, x);
            }
        }
        int count = nums.size();
        // 桶中存储区间的最大值和最小值
        std::vector<std::pair<int, int>> bucket(count+1, {INT32_MIN, INT32_MAX});
        for (const auto& x : nums) {
            int bucket_id = get_bucket_id(max, min, x, count);
            int tmp_max = bucket[bucket_id].first;
            int tmp_min = bucket[bucket_id].second;
            bucket[bucket_id].first = std::max(tmp_max, x);
            bucket[bucket_id].second = std::min(tmp_min, x);
        }
        int pre_max = INT32_MIN;
        // 差值有可能为负吗？不可能。如果是 [非空桶, 空桶, ... 空桶] 这种情况呢？没有这种情况
        int res_max = 0;
        bool flag = false;
        // 第一个桶肯定不为空桶
        for (const auto& x : bucket) {
            // 非空桶
            if (x.first != INT32_MIN || x.second != INT32_MAX) {
                if (flag == true) {
                    res_max = std::max(res_max, x.second - pre_max);
                    flag = false;
                }
                pre_max = x.first;
            } else {
                // 空桶的情况
                flag = true;
            }
        }
        return res_max;
    }

    int get_bucket_id(int64_t max, int64_t min, int64_t num, int64_t count) {
        int id = 0;
        if (max - min != 0) {
            id = (num - min) * count / (max - min);
        }
        return id;
    }
};

int main() {
    Solution s;
    // std::vector<int> arr{9, 3, 1, 10};
    // std::vector<int> arr{5, 5, 5, 5};
    std::vector<int> arr{1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
    auto res = s.get_max_gap(arr);
    std::cout << res << std::endl;
    return 0;
}
