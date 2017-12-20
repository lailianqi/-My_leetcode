#include <vector>
#include <climits>
using namespace std;
//没有写出来 其实这道题并不难 刚开始曲解了题目的意思
//题意确实比较难以理解
// typical AI MinMax problem
// https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation?page=2
// https://discuss.leetcode.com/topic/51530/improve-the-question-and-example/8
// https://discuss.leetcode.com/topic/68252/clarification-on-the-problem-description-problem-description-need-to-be-updated
//下面是自己修改答案写的dp 备忘录的写法
class Solution {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return helper(1, n, dp);
    }
    int helper(int i, int j, vector<vector<int>> &dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int result = INT_MAX;
        for (int k = i; k <= j; k++) {
            result = min(result,
                         k + max(helper(i, k - 1, dp), helper(k + 1, j, dp)));
        }
        dp[i][j] = result;
        return result;
    }
};
//基于上面的答案
//自己写的dp Bottom to top
// leetcode类似的答案
// https://discuss.leetcode.com/topic/51358/java-dp-solution
//类似算法设计与分析p47的解法
class Solution_0 {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int step = 2; step <= n; step++) {
            for (int i = 1; i <= n - step + 1; i++) {
                int j = i + step - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    dp[i][j] =
                        min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
//和上面稍微不同的写法
class Solution_1 {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int step = 2; step <= n; step++) {
            for (int i = 1; i <= n - step + 1; i++) {
                int j = i + step - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    dp[i][j] =
                        min(dp[i][j], k + max(k - 1 >= i ? dp[i][k - 1] : 0,
                                              j >= k + 1 ? dp[k + 1][j] : 0));
                }
            }
        }
        return dp[1][n];
    }
};
//再稍作修改的解法
class Solution_2 {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int step = 1; step < n; step++) {
            for (int i = 1; i + step <= n; i++) {
                int j = i + step;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    dp[i][j] =
                        min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};