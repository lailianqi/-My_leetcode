#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 直接看的LeetCode的答案
// https://leetcode.com/problems/largest-sum-of-averages/discuss/122739/C++JavaPython-Easy-Understood-Solution-with-Explanation
class Solution {
  public:
    double largestSumOfAverages(vector<int> &A, int K) {
        int m = A.size();
        memo = vector<vector<double>>(m + 1, vector<double>(m + 1, 0));
        double cur = 0;
        for (int i = 0; i < m; i++) {
            cur += A[i];
            memo[i + 1][1] = cur / (i + 1);
        }
        return helper(m, K, A);
    }
    double helper(int n, int k, vector<int> &A) {
        if (memo[n][k] > 0) {
            return memo[n][k];
        }
        if (n < k) {
            return 0;
        }
        double cur = 0;
        for (int i = n - 1; i > 0; i--) {
            cur += A[i];
            memo[n][k] = max(memo[n][k], helper(i, k - 1, A) + cur / (n - i));
        }
        return memo[n][k];
    }

  private:
    vector<vector<double>> memo;
};

// 第二种解法 来自LeetCode
// https://leetcode.com/problems/largest-sum-of-averages/discuss/122752/C++-DP
double largestSumOfAverages(vector<int> &A, int K) {
    if (A.empty() || K == 0)
        return 0;
    vector<vector<double>> dp(K + 1, vector<double>(A.size(), 0));
    vector<int> sum;
    sum.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
        sum.push_back(A[i] + sum.back());
    for (int k = 1; k <= K; k++) {
        for (int i = k - 1; i < A.size(); i++) {
            if (k == 1)
                dp[k][i] = double(sum[i]) / (i + 1);
            else {
                for (int j = k - 2; j < i; j++) {
                    dp[k][i] =
                        max(dp[k - 1][j] + double(sum[i] - sum[j]) / (i - j),
                            dp[k][i]);
                }
            }
        }
    }
    return dp[K][A.size() - 1];
}