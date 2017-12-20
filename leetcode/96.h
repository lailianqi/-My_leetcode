#include <vector>
using namespace std;
/*
F(i, j) = G(j-1) * G(i-j)
G(n) = F(1, n) + F(2, n) + ... + F(n, n);
=>
G(n) = G(0, n-1) + G(1, n-2) + .. + G(n-1) * G(0)
*/
class Solution {
  public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = dp[i] + dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};