#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// 这题没有写出来 直接看的leetcode的答案
// https://discuss.leetcode.com/topic/85030/hashmap-sort-solution-c
class Solution {
  public:
    int findLUSlength(vector<string> &strs) {
        unordered_map<string, int> dir;
        sort(strs.begin(), strs.end(),
             [](string &a, string &b) { return a.size() > b.size(); });
        for (int i = 0; i < strs.size(); i++) {
            dir[strs[i]]++;
        }
        for (int i = 0; i < strs.size(); i++) {
            if (dir[strs[i]] == 1) {
                int j = 0;
                for (; j < i; j++) {
                    if (isSubstring(strs[i], strs[j])) {
                        break;
                    }
                }
                if (j == i) {
                    return strs[i].size();
                }
            }
        }
        return -1;
    }
    bool isSubstring(string &a, string &b) {
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }
        return i == a.size();
    }
};

void test() {
    Solution s;
    vector<string> v = {"aaa", "aaa", "aa"};
    s.findLUSlength(v);
}