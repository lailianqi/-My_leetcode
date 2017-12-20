#include <cmath>
#include <climits>
#include <vector>
using namespace std;
//没有想出来
// leetcode的答案
// https://segmentfault.com/a/1190000003768736
// https://discuss.leetcode.com/topic/26400/an-easy-understanding-dp-solution-in-java
class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int j = 1;
            while (i - j * j >= 0) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
                j++;
            }
        }
        return dp[n];
    }
};