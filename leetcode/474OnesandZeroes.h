#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种写法 完美通过ac very good
// 发现LeetCode的解法和自己的解法居然99%的相似 震惊
// https://discuss.leetcode.com/topic/71438/c-dp-solution-with-comments
// https://discuss.leetcode.com/topic/76103/0-1-knapsack-detailed-explanation/2
class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            int zeroNums = countZeros(strs[i]);
            int oneNums = strs[i].size() - zeroNums;
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (j >= zeroNums && k >= oneNums) {
                        dp[j][k] =
                            max(dp[j][k], dp[j - zeroNums][k - oneNums] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
    int countZeros(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                res++;
            }
        }
        return res;
    }
};

//上面的稍微的改进版
class Solution_0 {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            int zeroNums = countZeros(strs[i]);
            int oneNums = strs[i].size() - zeroNums;
            for (int j = m; j >= zeroNums; j--) {
                for (int k = n; k >= oneNums; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroNums][k - oneNums] + 1);
                }
            }
        }
        return dp[m][n];
    }
    int countZeros(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                res++;
            }
        }
        return res;
    }
};