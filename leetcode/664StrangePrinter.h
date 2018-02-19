#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 没写出来 直接看的答案 就是一般的dp 但是我没想到
// https://leetcode.com/problems/strange-printer/discuss/106793/Java-solution-DP
// https://leetcode.com/problems/strange-printer/discuss/106792/Java-O(n3)-short-DP-Solution
class Solution {
  public:
    int strangePrinter(string s) {
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                dp[i][j] = i == j ? 1 : 1 + dp[i + 1][j];
                for (int k = i + 1; k <= j; k++) {
                    if (s[i] == s[k]) {
                        dp[i][j] =
                            min(dp[i][k - 1] + (k == m - 1 ? 0 : dp[k + 1][j]),
                                dp[i][j]);
                    }
                }
            }
        }
        return m == 0 ? 0 : dp[0][m - 1];
    }
};

// 备忘录的解法 来自LeetCode  但是不同于LeetCode  是上面dp解法的改写
// https://leetcode.com/problems/strange-printer/discuss/106811/C++-29ms-DP-solution
class Solution_0 {
  public:
    int strangePrinter(string s) {
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        return helper(s, 0, m - 1, dp);
    }
    int helper(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return dp[i][j] = 1;
        }
        if (dp[i][j]) {
            return dp[i][j];
        }
        dp[i][j] = 1 + helper(s, i + 1, j, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[i] == s[k]) {
                dp[i][j] = min(dp[i][j], helper(s, i, k - 1, dp) +
                                             helper(s, k + 1, j, dp));
            }
        }
        return dp[i][j];
    }
};