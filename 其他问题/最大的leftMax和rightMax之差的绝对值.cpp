#include <vector>
#include <iostream>

int maxABS(const std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    std::vector<int> leftArr(arr.size(), 0);
    leftArr[0] = arr[0];
    std::vector<int> rightArr(arr.size(), 0);
    rightArr[arr.size()-1] = arr[arr.size()-1];
    for (int i = 1; i < arr.size(); i++) {
        leftArr[i] = std::max(leftArr[i-1], arr[i]);
    }
    for (int i = arr.size()-2; i >= 0; i--) {
        rightArr[i] = std::max(rightArr[i+1], arr[i]);
    }
    int res = 0;
    for (int i = 0; i < arr.size()-2; i++) {
        res = std::max(res, std::abs(leftArr[i] - rightArr[i+1]));
    }
    return res;
}

int maxABS2(const std::vector<int>& arr) {
    int max = INT32_MIN;
    for (int i = 0; i < arr.size(); i++) {
        max = std::max(max, arr[i]);
    }
    return std::abs(max - std::min(arr[0], arr[arr.size()-1]));
}

int main() {
    std::vector<int> arr{2, 7, 3, 1, 1};
    int res = maxABS(arr);
    std::cout << res << std::endl;
    return 0;
}