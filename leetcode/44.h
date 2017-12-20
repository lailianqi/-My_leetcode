#include <iostream>
#include <string>
#include <vector>
using namespace std;
//自己的代码 参照提示链接
class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                               (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                } else {
                    dp[i][j] = dp[i][j - 1] ||
                               (i > 0 && dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
/*
https://discuss.leetcode.com/topic/17901/accepted-c-dp-solution-with-a-trick
Let's briefly summarize the idea of DP. We define the state P[i][j] to be whether s[0..i) matches p[0..j). The state equations are as follows:
P[i][j] = P[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j - 1] == '*'.
*/

void test() {
      Solution s;
      if (s.isMatch("a", "ba*"))
            cout << "yes" << endl;
      else {
            cout << "no" << endl;
      }
}