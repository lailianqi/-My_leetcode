#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 这题没写出来
// 来自LeetCode的答案
//  这一个链接 针对的这个类似的题目
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
// Base cases:
// T[-1][k][0] = 0, T[-1][k][1] = -Infinity
// T[i][0][0] = 0, T[i][0][1] = -Infinity

// Recurrence relation:
// T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
// T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])

// 这三个链接针对的是这题
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108868/Java-simple-DP-solutions.-O(n)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867/C++-concise-solution-O(n)-time-O(1)-space
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            int temp = buy;
            buy = max(buy, sell - prices[i]);
            sell = max(sell, temp + prices[i] - fee);
        }
        return sell;
    }
};