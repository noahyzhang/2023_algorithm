#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) {
        if (arr.empty() || arr.size() < k || k <= 0) {
            return std::vector<int>();
        }
        std::vector<int> heap(k, 0);
        for (size_t i = 0; i < k; ++i) {
            heap_insert(heap, arr[i], i);
        }
        for (size_t i = k; i < arr.size(); ++i) {
            if (arr[i] < heap[0]) {
                heap[0] = arr[i];
                heapify(heap, 0, k);
            }
        }
        return heap;
    }

private:
    void heap_insert(std::vector<int>& heap, int value, int index) {
        heap[index] = value;
        for (; index != 0;) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                std::swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapify(std::vector<int>& heap, int index, int heap_size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;
        for (; left < heap_size;) {
            if (heap[index] < heap[left]) {
                largest = left;
            }
            if (right < heap_size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                std::swap(heap[largest], heap[index]);
            } else {
                break;
            }
            index = largest;
            left = index * 2 + 1;
            right = index * 2 + 2;
        }
    }
};

void print_vec(const std::vector<int>& arr) {
    for (const auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr{0, 1, 1, 2, 4, 4, 1, 3, 3, 2};
    Solution s;
    auto res = s.getLeastNumbers(arr, 6);
    print_vec(res);
    return 0;
}
