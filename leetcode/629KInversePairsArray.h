#include <algorithm>
#include <vector>
using namespace std;
// 直接看的答案
// https://www.cnblogs.com/grandyang/p/7111385.html
// dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]

// https://leetcode.com/problems/k-inverse-pairs-array/discuss/104825/Shared-my-C++-O(n-*-k)-solution-with-explanation
// dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] + ..... +dp[i-1][j - i +
// 1]

//直接根据递归的公式写的答案 时间太慢 勉强过来oj
class Solution {
  public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int t = max(j - i + 1, 0); t <= j; t++) {
                    dp[i][j] += dp[i - 1][t];
                }
                dp[i][j] %= M;
            }
        }
        return dp[n][k];
    }
};

// 上面的改进版
// dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-i]
// https://leetcode.com/problems/k-inverse-pairs-array/discuss/104815/Java-DP-O(nk)-solution
// https://www.cnblogs.com/grandyang/p/7111385.html
class Solution_0 {
  public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if (j >= i) {
                    dp[i][j] -= dp[i - 1][j - i];
                }
                dp[i][j] = (dp[i][j] + M) % M;
            }
        }
        return dp[n][k];
    }
};