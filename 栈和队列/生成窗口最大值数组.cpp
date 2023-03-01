#include <vector>
#include <deque>
#include <iostream>

using namespace std;

void print_queue(std::deque<int> qu) {
    std::deque<int> help_qu;
    while (!qu.empty()) {
        help_qu.push_back(qu.back());
        std::cout << qu.back() << " ";
        qu.pop_back();
    }
    std::cout << std::endl;
    while (!help_qu.empty()) {
        qu.push_front(help_qu.front());
        help_qu.pop_front();
    }
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (!queue_.empty() && nums[i] < nums[queue_.back()]) {
                queue_.push_back(i);
            } else {
                for (; !queue_.empty() && nums[i] >= nums[queue_.back()]; ) {
                    queue_.pop_back();
                }
                // 直到队列为空了，或者 nums[i] < nums[queue_.back() 了，尾插 nums[i]
                queue_.push_back(i);
            }
            print_queue(queue_);
            // 插完之后，在每个阶段，我们都需要清理队列中过期的元素，从队头出。nums[i-k] 是当前滑动窗口第一个过期元素。
            // 注意，一定要在取滑动窗口最大值之前，让过期元素出队列，否则可能取到过期的元素
            if (queue_.front() == i-k) {
                queue_.pop_front();
            }
            // 当一个滑动窗口中所有元素都遍历了，就可以获取最大值了。
            // 也就是说，从第 k-1 次遍历，我们就得到了滑动窗口，后面都应该收集拿最大值
            if (queue_.back() >= k-1) {
                res.emplace_back(nums[queue_.front()]);
            }
        }
        return res;
    }

private:
    std::deque<int> queue_;
};

int main() {
    Solution s;
    std::vector<int> vec{1,3,-1,-3,5,3,6,7};
    // std::vector<int> vec{1, -1};
    int k = 3;
    auto res = s.maxSlidingWindow(vec, k);
    for (const auto& x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
