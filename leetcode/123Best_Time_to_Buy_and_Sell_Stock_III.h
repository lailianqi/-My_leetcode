#include <climits>
#include <vector>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on
day i.

Design an algorithm to find the maximum profit. You may complete at most two
transactions.
*/

/*
// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with
prices[ii]) using at most k transactions.
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj
in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any
money no matter how many times you can trade
*/

/*
the description of the algorithm is inaccurate. It doesn't match what the codes
really do.

//   f[k][i] : k transactions ENDs with prices[i]
//   f[k][i] = max(f[k][i - 1], f[k - 1][j] + prices[i] - prices[j]))
//j = 0..i-1
//=> f[k][i] = max(f[k][i - 1], prices[i] + max(f[k - 1][j] - prices[j]))
//j = 0..i-1
//temp = max(f[k - 1][j] - prices[j]);

*/
// LeetCode 的答案
// https://discuss.leetcode.com/topic/4766/a-clean-dp-solution-which-generalizes-to-k-transactions/32?page=2
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), num = 2;
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(num + 1, vector<int>(n, 0));
        for (int k = 1; k <= num; k++) {
            int temp = dp[k - 1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[k][i] = max(dp[k][i - 1], temp + prices[i]);
                temp = max(temp, dp[k - 1][i] - prices[i]);
            }
        }
        return dp[num][prices.size() - 1];
    }
};
// Leetco的解释
/*
To understand the hidden logic, you have to understand what these 4 variables
stand for.

sell2: Final profit.
buy2: Best profit so far, if you buy the stock not after Day i (2nd
transaction).
sell1: Best profit so far, if you sell the stock not after Day i (1st
transaction).
buy1: Minimum price to buy the stock.

The logic between buy1 and sell1 is quite straight forward. What you need to do
is simply find a minimum price to buy and sell it some days after.
Of course, sell1 won't update if the profit is not greater than before even if
you buy the stock at a lower price. Let's assume you sell the stock at Day a to
get the greatest profit for the 1st transaction, which stores in sell1.

Now comes the trick. Assume you find a better deal at Day b, sell1 get updated.
So you have 2 choice for buy2:

not update buy2, you still sell your stock at Day a. Nothing changed.
update buy2 with new sell1, which means you sell the stock at Day b.
buy2 = sell1 - price[i] means you sell you stock at Day b and buy it at Day i.
And Day i is definitely not early than Day b, which is the hidden logic.
*/
// https://discuss.leetcode.com/topic/39751/my-explanation-for-o-n-solution/9
class Solution_0 {
  public:
    int maxProfit(vector<int> &prices) {
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

// ----------------------------------二刷
// 最好的解法的链接
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39608/A-clean-DP-solution-which-generalizes-to-k-transactions
// 超时的做法
class Solution_1 {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int times = 2, m = prices.size();
        vector<vector<int>> dp(times + 1, vector<int>(m, 0));
        for (int k = 1; k <= times; k++) {
            for (int i = 1; i < m; i++) {
                int max_num = -prices[0];
                for (int j = 1; j <= i; j++) {
                    max_num = max(max_num, dp[k - 1][j - 1] - prices[j]);
                }
                dp[k][i] = max(dp[k][i - 1], max_num + prices[i]);
            }
        }
        return dp[times][m - 1];
    }
};

// 改进版 不超时
class Solution_12 {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int times = 2, m = prices.size();
        vector<vector<int>> dp(times + 1, vector<int>(m, 0));
        for (int k = 1; k <= times; k++) {
            int max_num = -prices[0];
            for (int i = 1; i < m; i++) {
                max_num = max(max_num, dp[k - 1][i - 1] - prices[i]);
                dp[k][i] = max(dp[k][i - 1], max_num + prices[i]);
            }
        }
        return dp[times][m - 1];
    }
};