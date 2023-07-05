#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int get_min_distance(
        const std::vector<std::string>& strs,
        const std::string& str1, const std::string& str2) {
        if (strs.size() < 2 || str1.empty() || str2.empty()) {
            return -1;
        }
        if (str1 == str2) {
            return 0;
        }
        int res = -1;
        int index_1 = -1, index_2 = -1;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i] == str1) {
                res = std::min(res, index_2 == -1 ? res : std::abs(i - index_2));
                index_1 = i;
            } else if (strs[i] == str2) {
                res = std::min(res, index_1 == -1 ? res : std::abs(i - index_1));
                index_2 = i;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int get_min_distance(
        const std::vector<std::string>& strs,
        const std::string& str1, const std::string& str2) {
        if (strs.size() < 2 || str1.empty() || str2.empty()) {
            return -1;
        }
        if (str1 == str2) {
            return 0;
        }
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i+1; j < strs.size(); j++) {
                mp[strs[i]][strs[j]] = j - i;
            }
        }
        if (mp.find(str1) != mp.end() && mp[str1].find(str2) != mp[str1].end()) {
            return mp[str1][str2];
        }
        return -1;
    }

private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> mp;
}
