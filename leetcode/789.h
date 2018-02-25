#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 73周周赛 未参加
// 自己的第一种方案 成功ac
// LeetCode的答案和我的第一种解法一模一样
// https://leetcode.com/problems/escape-the-ghosts/discuss/116507/Java-5-liner
// https://leetcode.com/problems/escape-the-ghosts/discuss/116511/Short-with-explanation-python
class Solution {
  public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int distance = abs(target[0]) + abs(target[1]);
        for (int i = 0; i < ghosts.size(); i++) {
            if (distance >= (abs(target[0] - ghosts[i][0]) +
                             abs(target[1] - ghosts[i][1]))) {
                return false;
            }
        }
        return true;
    }
};