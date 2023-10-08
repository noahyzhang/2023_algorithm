#include <vector>
#include <iostream>

struct MultiTree {
    int happy;
    std::vector<MultiTree*> subordinates;

    explicit MultiTree(int val) : happy(val) {}
};

// 当前节点能来
// 当前节点的 happy + 子节点不能来的 happy 值

// 当前节点不能来
// 子节点能来/不能来的 happy 值

struct Elem {
    // 能来的 happy 值
    int ok_happy;
    // 不能来的 happy 值
    int no_happy;

    Elem(int ok_happy_, int no_happy_) : ok_happy(ok_happy_), no_happy(no_happy_) {}
};

class Solution {
public:
    int get_part_max_happy(const MultiTree* tree) {
        auto info = recursion(tree);
        return std::max(info.ok_happy, info.no_happy);
    }

private:
    Elem recursion(const MultiTree* tree) {
        if (tree->subordinates.empty()) {
            return Elem(tree->happy, 0);
        }
        // 当前节点来的情况
        int ok = tree->happy;
        // 当前节点不来的情况
        int no = 0;
        for (const auto& x : tree->subordinates) {
            auto next_info = recursion(x);
            ok += next_info.no_happy;
            no += std::max(next_info.ok_happy, next_info.no_happy);
        }
        return Elem(ok, no);
    }
};

int main() {
    int n, root;
    std::cin >> n >> root;
    std::vector<MultiTree*> happy(n);
    int t;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        happy[i] = new MultiTree(t);
    }
    int u, v;
    for (int i = 1; i < n; ++i) {
        std::cin >> u >> v;
        happy[u-1]->subordinates.emplace_back(happy[v-1]);
    }
    Solution s;
    int res = s.get_part_max_happy(happy[root-1]);
    std::cout << res << std::endl;
    return 0;
}
