#include <iostream>
#include <vector>

class Solution {
private:
    struct HeapNode {
        // 值
        int val;
        // 代表那个数组
        int arr_num;
        // 代表数组中那个位置
        int arr_pos;
    };

public:
    void printTopK(std::vector<std::vector<int>> matrix, int topK) {
        int heap_size = matrix.size();
        std::vector<HeapNode> big_heap;
        big_heap.resize(heap_size);
        for (int i = 0; i < heap_size; i++) {
            int index = matrix[i].size()-1;
            // 数组个数小于 topK 个
            big_heap[i] = {matrix[i][index], i, index};
            heap_insert(big_heap, i);
        }
        std::cout << "topK: ";
        for (int i = 0; i < topK; i++) {
            if (heap_size == 0) {
                break;
            }
            auto& cur_node = big_heap[0];
            std::cout << cur_node.val << " ";
            if (cur_node.arr_pos > 0) {
                big_heap[0] = {matrix[cur_node.arr_num][cur_node.arr_pos-1], cur_node.arr_num, cur_node.arr_pos-1};
                heapify(big_heap, 0, heap_size);
            } else {
                std::swap(big_heap[0], big_heap[heap_size-1]);
                heapify(big_heap, 0, --heap_size);
            }
        }
        std::cout << std::endl;
    }

private:
    void heap_insert(std::vector<HeapNode>& big_heap, int index) {
        for (; index != 0;) {
            int parent = (index - 1) / 2;
            if (big_heap[parent].val < big_heap[index].val) {
                std::swap(big_heap[parent], big_heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapify(std::vector<HeapNode>& big_heap, int index, int heap_size) {
        int left_child = index*2 + 1;
        int right_child = index*2 + 2;
        int largest = index;
        for (; left_child < heap_size;) {
            if (big_heap[left_child].val > big_heap[index].val) {
                largest = left_child;
            }
            if (right_child < heap_size && big_heap[right_child].val > big_heap[largest].val) {
                largest = right_child;
            }
            if (largest != index) {
                std::swap(big_heap[largest], big_heap[index]);
            } else {
                break;
            }
            index = largest;
            left_child = index * 2 + 1;
            right_child = index * 2 + 2;
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix{
      {219, 405, 538, 845, 971},
      {148, 558},
      {52, 99, 348, 691},
    };
    s.printTopK(matrix, 5);
    return 0;
}
