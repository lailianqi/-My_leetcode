#include <string>
using namespace std;
//超时 99 / 101 test cases passed.
class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        vector<vector<bool>> valid(s1.length() + 1,
                                   vector<bool>(s2.length() + 1, true));
        return doIsInterleave(s1, 0, s2, 0, s3, 0, valid);
    }
    bool doIsInterleave(string s1, int i, string s2, int j, string s3, int k,
                        vector<vector<bool>> &valid) {
        if (!valid[i][j])
            return false;
        if (k == s3.length())
            return true;
        bool result = i < s1.length() && s1[i] == s3[k] &&
                          doIsInterleave(s1, i + 1, s2, j, s3, k + 1, valid) ||
                      j < s2.length() && s2[j] == s3[k] &&
                          doIsInterleave(s1, i, s2, j + 1, s3, k + 1, valid);
        if (!result)
            valid[i][j] = false;
        return result;
    }
    //自己写的版本 超时
    bool doIsInterleave1(string s1, int n, string s2, int m, string s3, int k) {
        if (n == s1.length() && m == s2.length() && k == s3.length()) {
            return true;
        }
        if (n == s1.length()) {
            if (s2[m] == s3[k]) {
                return doIsInterleave(s1, n, s2, m + 1, s3, k + 1);
            } else {
                return false;
            }
        }
        if (m == s2.length()) {
            if (s1[n] == s3[k]) {
                return doIsInterleave(s1, n + 1, s2, m, s3, k + 1);
            } else {
                return false;
            }
        }

        if (s1[n] == s3[k] || s2[m] == s3[k]) {
            if (s1[n] == s3[k] && s2[m] == s3[k]) {
                return doIsInterleave(s1, n + 1, s2, m, s3, k + 1) ||
                       doIsInterleave(s1, n, s2, m + 1, s3, k + 1);
            } else if (s1[n] == s3[k]) {
                return doIsInterleave(s1, n + 1, s2, m, s3, k + 1);
            } else {
                return doIsInterleave(s1, n, s2, m + 1, s3, k + 1);
            }
        }
        return false;
    }
};
// dp的写法
class Solution_0 {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        vector<vector<bool>> dp(s1.length() + 1,
                                vector<bool>(s2.length() + 1, false));
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) ||
                               (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};