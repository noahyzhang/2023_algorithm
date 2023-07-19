#include <vector>
#include <iostream>

// 堆排序的做法
// 而且申请了新空间
class Solution {
public:
    int findKthLargest(const std::vector<int>& nums, int k) {
        if (nums.size() < k) {
            return -1;
        }
        // 建立小根堆(K个元素)
        std::vector<int> heap(k, 0);
        for (int i = 0; i < k; i++) {
            build_heap(heap, nums[i], i);
        }
        // 处理数组中剩余元素
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > heap[0]) {
                re_cal_heap(heap, nums[i]);
            }
        }
        // 返回堆顶元素即可
        return heap[0];
    }

private:
    void build_heap(std::vector<int>& heap, int elem, int last) {
        heap[last] = elem;
        while (last > 0 && heap[last] < heap[(last-1)/2]) {
            std::swap(heap[last], heap[(last-1)/2]);
            last = (last-1) / 2;
        }
    }
    void re_cal_heap(std::vector<int>& heap, int elem) {
        heap[0] = elem;
        int last = heap.size()-1;
        int i = 0;
        while (true) {
            int min_pos = i;
            if (i*2+1 <= last && heap[i] > heap[i*2+1]) {
                min_pos = i*2+1;
            }
            if (i*2+2 <= last && heap[min_pos] > heap[i*2+2]) {
                min_pos = i*2+2;
            }
            if (min_pos == i) {
                break;
            }
            std::swap(heap[i], heap[min_pos]);
            i = min_pos;
        }
    }
};

// 基于快排的思路
class Solution2 {

};

int main() {
    std::vector<int> nums{3,2,3,1,2,4,5,5,6};
    Solution s;
    auto res = s.findKthLargest(nums, 4);
    std::cout << res << std::endl;
    return 0;
}
