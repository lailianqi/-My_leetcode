#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法  成功ac
// LeetCode的答案与下面的答案一模一样
// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/110111/Easy-to-understand-C++-using-DP-with-detailed-explanation
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int m = cost.size();
        vector<int> dp(m, 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < m; i++) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[m - 1], dp[m - 2]);
    }
};

// 自己对上面的改写版 自己的第二种解法
// leetcode也有和这个答案思路一模一样的答案
// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/110104/Easy-to-understand-Python-solution-O(1)-space
class Solution_0 {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int m = cost.size();
        int prev = cost[0], cur = cost[1];
        for (int i = 2; i < m; i++) {
            int temp = cur;
            cur = min(cur, prev) + cost[i];
            prev = temp;
        }
        return min(prev, cur);
    }
};