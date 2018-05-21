#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来 直接看的答案 好题
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119879/C++JavaPython-Easy-Understood-DP-Solution
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119830/Python-14-line-O(1)-space-O(n)-time-DP-solution
/*
For $i in [1, N]$:
If A[i]>A[i-1] and B[i]>B[i-1] (they are in order without swap):
dp[i][0]=min(dp[i][0], dp[i-1][0]) (no swap at i-1 and no swap at i)
dp[i][1]=min(dp[i][1], dp[i-1][1]+1) (swap at i-1 so swap at i to make in order)
If A[i]>B[i-1] and B[i]>A[i-1] (they are in order with a swap):
dp[i][0]=min(dp[i][0], dp[i-1][1]) (swap at i-1, no need to swap at i)
dp[i][1]=min(dp[i][1], dp[i-1][0]+1) (no swap at i-1, so swap at i)
The two cases don't conflict with each other, so we choose minimum of them when
both holds.
*/
class Solution {
  public:
    int minSwap(vector<int> &A, vector<int> &B) {
        int m = A.size();
        vector<vector<int>> dp(m, vector<int>(2, 0));
        dp[0][1] = 1;
        for (int i = 1; i < m; i++) {
            dp[i][0] = m, dp[i][1] = m; // no_swap,swap
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            }
        }
        return min(dp[m - 1][0], dp[m - 1][1]);
    }
};