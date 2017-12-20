#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
//这种方法存在问题，过不去
// 发现思路错了
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());
        int result = -1;
        helper(coins, coins.size() - 1, amount, 0, result);
        return result;
    }
    bool helper(vector<int> &coins, int start, int amount, int sum,
                int &result) {
        if (amount < 0) {
            return false;
        }
        if (amount == 0) {
            result = sum;
            return true;
        }
        for (int i = start; i >= 0; i--) {
            if (helper(coins, i, amount - coins[i], sum + 1, result)) {
                //   cout << coins[i] << " ";
                return true;
            }
        }
        return false;
    }
};

//上面的改进版
//会超时
class Solution_2 {
  public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());
        int result = INT_MAX;
        helper(coins, coins.size() - 1, amount, 0, result);
        return result == INT_MAX ? -1 : result;
    }
    void helper(vector<int> &coins, int start, int amount, int sum,
                int &result) {
        if (amount < 0) {
            return;
        }
        if (amount == 0) {
            result = min(sum, result);
            return;
        }
        for (int i = start; i >= 0; i--) {
            helper(coins, i, amount - coins[i], sum + 1, result);
        }
    }
};

class Solution_3 {
  public:
    int defaultValue = 0;
    int coinChange(vector<int> &coins, int amount) {
        defaultValue = amount + 1;
        vector<int> dp(amount + 1, defaultValue);
        dp[0] = 0;
        helper(coins, amount, dp);
        return dp[amount] > amount ? -1 : dp[amount];
    }
    int helper(vector<int> &coins, int amount, vector<int> &dp) {
        if (dp[amount] != defaultValue) {
            return dp[amount];
        }
        for (int i = 0; i < coins.size(); i++) {
            if (amount >= coins[i]) {
                dp[amount] =
                    min(dp[amount], helper(coins, amount - coins[i], dp) + 1);
            }
        }
        if (dp[amount] == defaultValue) {
            dp[amount] = defaultValue + 1;
        }
        return dp[amount];
    }
};

// leetcode的答案
// dp的写法，写的非常的好
// https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution?page=1
class Solution_0 {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

void test() {
    Solution_2 s;
    vector<int> coins = {186, 419, 83, 408};
    cout << s.coinChange(coins, 6249);
}