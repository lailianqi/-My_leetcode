#include <vector>
#include <cmath>
using namespace std;
class Solution {
  public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};

class Solution_0 {
  public:
    // Using the Fibonacci formular to get the answer directly
    // https://discuss.leetcode.com/topic/30638/using-the-fibonacci-formular-to-get-the-answer-directly
    int climbStairs(int n) {
        n++;
        double root5 = pow(5, 0.5);
        double result =
            1 / root5 * (pow((1 + root5) / 2, n) - pow((1 - root5) / 2, n));
        return (int)(result);
    }
};