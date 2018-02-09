#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
// LeetCode上面类似的答案
// https://discuss.leetcode.com/topic/92782/c-9-lines-hash-table-easy-to-understand
// https://discuss.leetcode.com/topic/90534/java-o-n-m-time-o-n-space
class Solution {
  public:
    vector<string> findRestaurant(vector<string> &list1,
                                  vector<string> &list2) {
        // unordered_set<string> dir;
        int minValue = INT_MAX;
        vector<string> res;
        unordered_map<string, int> dir;
        for (int i = 0; i < list1.size(); i++) {
            dir[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (dir.find(list2[i]) != dir.end()) {
                if (minValue > (i + dir[list2[i]])) {
                    res.clear();
                    res.push_back(list2[i]);
                    minValue = i + dir[list2[i]];
                } else if (minValue == (i + dir[list2[i]])) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};