#include <unordered_set>
#include <vector>
#include <memory>
#include <iostream>

struct Node {
    int left;
    int right;
    int val;

    Node(int l, int r, int v) : left(l), right(r), val(v) {}
};

class Solution {
public:
    std::vector<int> topK_sum(const std::vector<int>& arr1, const std::vector<int>& arr2, int topK) {
        if (arr1.empty() || arr2.empty() || topK < 1) {
            return {};
        }
        topK = std::min(static_cast<uint64_t>(topK), arr1.size()*arr2.size());
        heap.resize(topK);
        int left_pos = arr1.size()-1;
        int right_pos = arr2.size()-1;
        int heap_size = 0;
        heap_insert(heap_size++, left_pos, right_pos, arr1[left_pos]+arr2[right_pos]);
        int res_index = 0;
        std::vector<int> res_vec(topK, 0);
        while (res_index < topK) {
            auto node = get_heap_top(heap_size--);
            res_vec[res_index++] = node->val;
            int tmp_left = node->left-1;
            int tmp_right = node->right;
            if (tmp_left >= 0 && st.find(hash(tmp_left, tmp_right)) == st.end()) {
                heap_insert(heap_size++, tmp_left, tmp_right, arr1[tmp_left]+arr2[tmp_right]);
                st.insert(hash(tmp_left, tmp_right));
            }
            tmp_left = node->left;
            tmp_right = node->right-1;
            if (tmp_right >= 0 && st.find(hash(tmp_left, tmp_right)) == st.end()) {
                heap_insert(heap_size++, tmp_left, tmp_right, arr1[tmp_left]+arr2[tmp_right]);
                st.insert(hash(tmp_left, tmp_right));
            }
            delete node;
            node = nullptr;
        }
        while (heap_size > 0) {
            auto node = get_heap_top(heap_size--);
            delete node;
        }
        return res_vec;
    }

private:
    void heap_insert(int index, int left, int right, int value) {
        heap[index] = new Node(left, right, value);
        int parent = (index-1)/2;
        while (index != 0) {
            if (heap[index]->val > heap[parent]->val) {
                std::swap(heap[index], heap[parent]);
                index = parent;
                parent = (index-1)/2;
            } else {
                break;
            }
        }
    }

    Node* get_heap_top(int heap_size) {
        auto res = heap[0];
        heap[0] = heap[heap_size-1];
        heap[--heap_size] = nullptr;
        heapify(0, heap_size);
        return res;
    }

    void heapify(int index, int heap_size) {
        int left = index*2+1;
        int right = index*2+2;
        int max_pos = index;
        while (left < heap_size) {
            if (heap[left]->val > heap[index]->val) {
                max_pos = left;
            }
            if (right < heap_size && heap[right]->val > heap[max_pos]->val) {
                max_pos = right;
            }
            if (max_pos == index) {
                break;
            }
            std::swap(heap[max_pos], heap[index]);
            index = max_pos;
            left = index*2+1;
            right = index*2+2;
        }
    }

    std::string hash(int left, int right) {
        return std::to_string(left) + std::to_string(right);
    }

private:
    std::vector<Node*> heap;
    std::unordered_set<std::string> st;
};

int main() {
    Solution s;
    std::vector<int> arr1{1, 2, 3, 4, 5};
    std::vector<int> arr2{3, 5, 7, 9, 11};
    auto res = s.topK_sum(arr1, arr2, 4);
    for (const auto& x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
