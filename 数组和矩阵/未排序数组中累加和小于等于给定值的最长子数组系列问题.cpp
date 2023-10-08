#include <vector>
#include <iostream>

class Solution {
public:
    int get_max_len(const std::vector<int>& arr, int k) {
        std::vector<int> help_arr(arr.size()+1, 0);
        int sum = 0;
        // 没有任何一个数时的累加和为 0
        help_arr[0] = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            help_arr[i+1] = std::max(sum, help_arr[i]);
        }
        sum = 0;
        int res = 0;
        int pre = 0;
        int len = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            pre = get_less_index(help_arr, sum-k);
            len = pre == -1 ? 0 : i-pre+1;
            res = std::max(res, len);
        }
        return res;
    }

private:
    int get_less_index(const std::vector<int>& arr, int num) {
        int low = 0;
        int high = arr.size() - 1;
        int mid = 0;
        int res = -1;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (arr[mid] >= num) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return res;
    }
};

// 如果是循环数组呢？并且返回左右下标的值
// 循环数组这里，以每个位置为起点，此位置的前一个位置为终点
// 返回左右下标的值，使用两个值，保存下标即可

class Solution2 {
public:
    std::pair<int, int> get_cycle_arr_max_len(const std::vector<int>& arr, int k) {
        int left = 0, right = 0;
        int len = 0;
        for (int i = 0; i < arr.size(); i++) {
            std::vector<int> tmp_arr;
            int end = i == 0 ? arr.size()-1 : i-1;
            for (int j = i; j != end; j++, j%=arr.size()) {
                tmp_arr.emplace_back(arr[j]);
            }
            tmp_arr.emplace_back(arr[end]);
            print_arr(tmp_arr);
            auto res = get_max_len(tmp_arr, k);
            if (res.second - res.first + 1 > len) {
                len = res.second - res.first + 1;
                left = res.first+i >= arr.size() ? (res.first+i)%arr.size() : res.first+i;
                right = res.second+i >= arr.size() ? (res.second+i)%arr.size() : res.second+i;
            }
        }
        return std::pair<int, int>(left, right);
    }

private:
    std::pair<int, int> get_max_len(const std::vector<int>& arr, int k) {
        std::vector<int> help_arr(arr.size()+1, 0);
        int sum = 0;
        // 没有任何一个数时的累加和为 0
        help_arr[0] = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            help_arr[i+1] = std::max(sum, help_arr[i]);
        }
        sum = 0;
        int res = 0;
        int pre = 0;
        int len = 0;
        int left = 0, right = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            pre = get_less_index(help_arr, sum-k);
            len = pre == -1 ? 0 : i-pre+1;
            if (len > res) {
                left = pre;
                right = i;
                res = len;
            }
        }
        return std::pair<int, int>(left, right);
    }

    int get_less_index(const std::vector<int>& arr, int num) {
        int low = 0;
        int high = arr.size() - 1;
        int mid = 0;
        int res = -1;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (arr[mid] >= num) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return res;
    }

    void print_arr(const std::vector<int>& arr) {
        for (const auto& x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr{1, 2, 2, 1, 1, 1, 1};
    int k = 5;

    // Solution s;
    // int res = s.get_max_len(arr, k);
    // std::cout << res << std::endl;

    Solution2 s2;
    auto res = s2.get_cycle_arr_max_len(arr, k);
    std::cout << res.first << " " << res.second << std::endl;
    return 0;
}
