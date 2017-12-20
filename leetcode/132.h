#include <string>
#include <vector>
using namespace std;
//错误:Time Limit Exceeded
class Solution {
  public:
    int minNum = INT_MAX;
    int minCut(string s) {
        partition(s, 0, s.size() - 1, -1);
        return minNum;
    }

    void partition(string &s, int begin, int end, int deep) {
        if (begin > end || minNum <= deep) {
            minNum = min(minNum, deep);
            return;
        }
        for (int i = end; i >= begin; i--) {
            if (judgePalindromic(s, begin, i)) {
                partition(s, i + 1, end, deep + 1);
            }
        }
    }
    bool judgePalindromic(const string &s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
// Leetcode的答案
// https://discuss.leetcode.com/topic/2840/my-solution-does-not-need-a-table-for-palindrome-is-it-right-it-uses-only-o-n-space?page=1
class Solution_0 {
  public:
    int minCut(string s) {
        int m = s.size();
        vector<int> dp(m + 1, 0);
        for (int i = 0; i <= m; i++) {
            dp[i] = i - 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; i - j >= 0 && i + j < m && s[i - j] == s[i + j];
                 j++) {
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j]);
            }
            for (int j = 1;
                 i - j + 1 >= 0 && i + j < m && s[i - j + 1] == s[i + j]; j++) {
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j + 1]);
            }
        }
        return dp[m];
    }
};

//参考另外一个答案后写出的全新的解法,发现写出来的思路和下面的答案是一样的
// https://discuss.leetcode.com/topic/6414/dp-solution-some-thoughts
class Solution_1 {
  public:
    int minCut(string s) {
        int m = s.size();
        vector<vector<bool>> dp(m, vector<bool>(m, false));
        vector<int> distance(m, 0);
        for (int i = 0; i < s.size(); i++) {
            distance[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    distance[i] =
                        min(distance[i], j == 0 ? 0 : distance[j - 1] + 1);
                }
            }
        }
        return distance[m - 1];
    }
};