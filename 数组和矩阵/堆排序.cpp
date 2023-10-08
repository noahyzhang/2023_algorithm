#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> heap_sort(const std::vector<int>& arr) {
        if (arr.empty() || arr.size() == 1) {
            return arr;
        }
        int len = arr.size();
        // 先构建一个大根堆
        for (int i = len/2-1; i >= 0; i--) {
            heapify(arr, i, len);
        }
        // 将堆顶元素与数组的最后一位互换，相当于排好了数组的最后一位
        // 依次将堆顶元素换到数组末尾，并且减少 len，直到排好序
        for ()
    }

private:
    void heapify(const std::vector<int>& arr, int i, int len) {
        
    }
};