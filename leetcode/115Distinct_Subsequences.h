#include <string>
#include <vector>
using namespace std;

/*
Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
*/

/*
Well, a dynamic programming problem. Let's first define its state dp[i][j] to be
the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. Then we have
the following state equations:

General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j -
1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.
Now let's give brief explanations to the four equations above.

If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1] and
thus all the number of distinct subsequences will simply be those in s[0..j -
2], which corresponds to dp[i][j - 1];
If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts:
those with s[j - 1] and those without;
An empty string will have exactly one subsequence in any string :-)
Non-empty string will have no subsequences in an empty string.
Putting these together, we will have the following simple codes (just like
translation :-)):
*/
class Solution {
  public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] != s[j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
//第一种的简写方案
class Solution_0 {
  public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] +
                           (t[i - 1] != s[j - 1] ? 0 : dp[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
};

class Solution_1 {
  public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<int> cur(m + 1, 0);
        cur[0] = 1;
        for (int j = 1; j <= n; j++) {
            int pre = 1;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
                pre = temp;
            }
        }
        return cur[m];
    }
};

// -------------------二刷
class Solution {
  public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] != t[j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};