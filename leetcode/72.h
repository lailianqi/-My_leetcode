#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//参考的代码
// https://discuss.leetcode.com/topic/17639/20ms-detailed-explained-c-solutions-o-n-space
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

//改进版代码
class Solution_0 {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> dp(n + 1, 0);
        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre;
                } else {
                    dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
                }
                pre = temp;
            }
        }
        return dp[n];
    }
};
void test() {
    Solution s;
    cout << s.minDistance("", "") << endl;
}