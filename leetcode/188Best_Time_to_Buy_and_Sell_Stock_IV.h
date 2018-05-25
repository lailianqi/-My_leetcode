#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using namespace std;
//存在内存爆炸和超时的情况，答案并不对
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size(), num = min(k, n);
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(num + 1, vector<int>(n, 0));
        for (int t = 1; t <= num; t++) {
            int temp = dp[t - 1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[t][i] = max(dp[t][i - 1], temp + prices[i]);
                temp = max(temp, dp[t - 1][i] - prices[i]);
            }
        }
        return dp[num][prices.size() - 1];
    }
};
// 这是自己写出的最优化方案
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54113/A-Concise-DP-Solution-in-Java
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54117/Clean-Java-DP-solution-with-comment
class Solution_0 {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size(), num = min(n, k);
        if (num >= n / 2)
            return quickSolve(prices);
        vector<int> dp(n, 0);
        for (int t = 1; t <= num; t++) {
            int temp = dp[0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                int pre = dp[i];
                dp[i] = max(dp[i - 1], temp + prices[i]);
                temp = max(temp, pre - prices[i]);
            }
        }
        return dp[prices.size() - 1];
    }
    int quickSolve(vector<int> &prices) {
        int len = prices.size(), profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }
};