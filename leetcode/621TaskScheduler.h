#include <algorithm>
#include <vector>
using namespace std;
// 这题没写出来 题目一开始就没有看懂
// 答案链接
// https://www.cnblogs.com/grandyang/p/7098764.html
class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> dir(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            dir[tasks[i] - 'A']++;
        }
        sort(dir.begin(), dir.end());
        int i = 25, mx = dir[25];
        for (; i >= 0 && dir[i] == dir[25]; i--) {
        }
        return max((int)tasks.size(), (mx - 1) * (n + 1) + 25 - i);
    }
};

// 另外的一种解法 参考是下面的链接 虽然题目不一样
// https://leetcode.com/problems/rearrange-string-k-distance-apart