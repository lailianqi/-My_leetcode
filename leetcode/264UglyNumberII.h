#include <vector>
using namespace std;
//没有想出来
// leetcode的答案
//思路 3个pointer的移动
// https://discuss.leetcode.com/topic/21882/my-16ms-c-dp-solution-with-short-explanation
// https://discuss.leetcode.com/topic/21791/o-n-java-solution/2?page=1
class Solution {
  public:
    int nthUglyNumber(int n) {
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(dp[t2] * 2, dp[t3] * 3), dp[t5] * 5);
            if (dp[i] == dp[t2] * 2)
                t2++;
            if (dp[i] == dp[t3] * 3)
                t3++;
            if (dp[i] == dp[t5] * 5)
                t5++;
        }
        return dp[n - 1];
    }
};