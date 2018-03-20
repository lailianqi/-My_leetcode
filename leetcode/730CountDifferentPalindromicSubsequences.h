#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题没写出出来 直接看的LeetCode的答案 实在没想到dp的递归式子
// https://csacademy.com/contest/round-57/task/distinct-palindromes/solution/
// 递推的式子 http://blog.csdn.net/lili0710432/article/details/78659583
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/112758/General-Solution-Using-JAVA-Very-clean
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109509/Accepted-Java-Solution-using-memoization
// https://www.cnblogs.com/grandyang/p/7942040.html
// http://www.mamicode.com/info-detail-2108658.html
class Solution {
  public:
    int countPalindromicSubsequences(string S) {
        int m = S.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            dp[i][i] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                if (S[i] == S[j]) {
                    int left = i + 1, right = j - 1;
                    while (left <= right && S[left] != S[j]) {
                        left++;
                    }
                    while (left <= right && S[right] != S[j]) {
                        right--;
                    }
                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] =
                            dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007
                                        : dp[i][j] % 1000000007;
            }
        }
        return dp[0][m - 1];
    }
};

// 第二种解法 来自LeetCode 最容易懂的方案  但是运行的效率一般
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109509/Accepted-Java-Solution-using-memoization
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109510/Python-DP+DFS-O(n2)-with-Explanations
// https://www.cnblogs.com/grandyang/p/7942040.html
class Solution_0 {
  public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        vector<vector<int>> chars(26, vector<int>());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            chars[S[i] - 'a'].push_back(i);
        }
        return helper(S, chars, 0, n, memo);
    }
    int helper(string &s, vector<vector<int>> &chars, int start, int end,
               vector<vector<int>> &memo) {
        if (start >= end) {
            return 0;
        }
        if (memo[start][end] > 0) {
            return memo[start][end];
        }
        long res = 0;
        for (int i = 0; i < chars.size(); i++) {
            auto nStart = lower_bound(chars[i].begin(), chars[i].end(), start),
                 nEnd = lower_bound(chars[i].begin(), chars[i].end(), end) - 1;
            if (nStart == chars[i].end() || *nStart >= end) {
                continue;
            }
            res++;
            if (nStart != nEnd) {
                res++;
            }
            res += helper(s, chars, *nStart + 1, *nEnd, memo);
        }
        memo[start][end] = res % int(1e9 + 7);
        return memo[start][end];
    }
};