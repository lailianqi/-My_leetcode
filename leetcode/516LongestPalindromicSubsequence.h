#include <string>
#include <vector>
using namespace std;
//没想到dp 真是非常的不应该 直接看的leetcode的答案 这道题其实不难
//下面的两个解法来自同一个链接 solution 和 solution_1
// https://discuss.leetcode.com/topic/78603/straight-forward-java-dp-solution
// https://discuss.leetcode.com/topic/78603/straight-forward-java-dp-solution/19
/*
dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
State transition:
dp[i][j] = dp[i+1][j-1] + 2 if s.charAt(i) == s.charAt(j)
otherwise, dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1])
Initialization: dp[i][i] = 1
*/
class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = m - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < m; j++) {
                if (s[i] == s[j]) {
                    // 注释部分的代码是不需要的 和不注释的代码功能一样
                    // 例如dp[4][3]本身就等于0
                    // dp[i][j] = (j - i > 1 ? dp[i + 1][j - 1] : 0) + 2;
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
//备忘录的写法
class Solution_0 {
  public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(s, 0, m - 1, dp);
    }
    int helper(string &s, int left, int right, vector<vector<int>> &dp) {
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        if (left > right)
            return 0;
        if (left == right)
            return 1;
        if (s[left] == s[right]) {
            return dp[left][right] = helper(s, left + 1, right - 1, dp) + 2;
        } else {
            return dp[left][right] = max(helper(s, left + 1, right, dp),
                                         helper(s, left, right - 1, dp));
        }
    }
};

//另外的一种写法 用的长度 来自leetcode的答案
// https://discuss.leetcode.com/topic/78630/evolve-from-brute-force-to-dp
class Solution_1 {
  public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        vector<vector<int>> dp(m + 1, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            dp[1][i] = 1;
        }
        for (int len = 2; len <= m; len++) {
            for (int i = 0; (i + len - 1) < m; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[len][i] = dp[len - 2][i + 1] + 2;
                } else {
                    dp[len][i] = max(dp[len - 1][i + 1], dp[len - 1][i]);
                }
            }
        }
        return dp[m][0];
    }
};

//上面的改写版 0(n)的空间 还算非常的巧妙
class Solution_2 {
  public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        vector<int> dp(m, 0);
        vector<int> prev(m, 0);
        for (int len = 1; len <= m; len++) {
            for (int i = 0; (i + len - 1) < m; i++) {
                int temp = dp[i];
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i] = i == j ? 1 : prev[i + 1] + 2;
                } else {
                    dp[i] = max(dp[i + 1], dp[i]);
                }
                prev[i] = temp;
            }
        }
        return dp[0];
    }
};
void test() {
    Solution s;
    string tmep = "aa";
    s.longestPalindromeSubseq(tmep);
}