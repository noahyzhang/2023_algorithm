#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int get_num(int n) {
        if (n < 1) {
            return 0;
        }
        std::vector<int> record(n, 0);
        return process(record, 0, n);
    }

private:
    int process(std::vector<int>& record, int i, int n) {
        if (i == n) {
            return 1;
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (invalid(record, i, j)) {
                record[i] = j;
                res += process(record, i+1, n);
            }
        }
        return res;
    }
    bool invalid(const std::vector<int>& record, int i, int j) {
        for (int k = 0; k < i; k++) {
            if (record[k] == j || std::abs(i-k) == std::abs(j-record[k])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    auto res = s.get_num(13);
    std::cout << res << std::endl;
    return 0;
}
