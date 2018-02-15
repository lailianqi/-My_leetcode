#include <string>
#include <vector>
using namespace std;
//自己的第一种方案 不知为何不过
class Solution {
  public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        int M = 1000000007;
        int m = s.length();
        vector<int> dp(m + 1, 0);
        dp[0] = 1, dp[1] = convertWays(s[0]);
        for (int i = 2; i <= s.size(); i++) {
            dp[i] = convertWays(s[i - 1]) * dp[i - 1];
            if (s[i - 1] != '*') {
                if (s[i - 2] == '*') {
                    dp[i] += dp[i - 2] + dp[i - 2] * (s[i - 1] < '7' ? 1 : 0);
                } else {
                    dp[i] += ((s[i - 2] == '1') ||
                                      (s[i - 2] == '2' && s[i - 1] < '7')
                                  ? 1
                                  : 0) *
                             dp[i - 2];
                }
            } else {
                if (s[i - 2] == '*') {
                    dp[i] += 15 * dp[i - 2];
                } else {
                    dp[i] += (s[i - 2] == '1' ? 9 : 0) * dp[i - 2];
                    dp[i] += (s[i - 2] == '2' ? 6 : 0);
                }
            }
            dp[i] %= M;
        }
        return dp[m];
    }
    int convertWays(char ch) {
        if (ch == '*')
            return 9;
        if (ch == '0')
            return 0;
        return 1;
    }
};
// 上面的改写版 参考自LeetCode 但是没发现和上面的逻辑区别
// https://leetcode.com/problems/decode-ways-ii/discuss/105275/Java-DP-O(n)-time-and-O(1)-space
class Solution_0 {
  public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        int M = 1000000007, m = s.length();
        vector<long> dp(m + 1, 0);
        dp[0] = 1, dp[1] = convertWays(s[0]);
        for (int i = 2; i <= s.size(); i++) {
            dp[i] = (convertWays(s[i - 1]) * dp[i - 1] +
                     convertWays(s[i - 2], s[i - 1]) * dp[i - 2]) %
                    M;
        }
        return dp[m];
    }
    int convertWays(char ch) {
        if (ch == '*')
            return 9;
        if (ch == '0')
            return 0;
        return 1;
    }
    int convertWays(char ch1, char ch2) {
        if (ch1 == '*' && ch2 == '*') {
            return 15;
        }
        if (ch1 == '*' && ch2 != '*') {
            return ch2 < '7' ? 2 : 1;
        }
        if (ch1 != '*' && ch2 == '*') {
            return ch1 == '1' ? 9 : ch1 == '2' ? 6 : 0;
        }
        return ch1 == '1' || (ch1 == '2' && ch2 < '7') ? 1 : 0;
    }
};
void test() {
    Solution s;
    string str = "1*";
    s.numDecodings(str);
}