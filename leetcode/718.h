#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac
// LeetCode的答案和我的第一种解法其实一模一样
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109039/Concise-Java-DP:-Same-idea-of-Longest-Common-Substring
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC++-Clean-Code-8-lines
class Solution {
  public:
    int findLength(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size(), res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

// leetcode的答案 python的解法 写的不错
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109026/Python-Concise-DP
/*
class Solution(object):
    def findLength(self, A, B):
        dp = [[0 for _ in range(len(B) + 1)] for _ in range(len(A) + 1)]
        for i in range(1, len(A) + 1):
            for j in range(1, len(B) + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
        return max(max(row) for row in dp)
*/

// sp大神的暴力的解法
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109062/Brute-Force-Python
/*
def findLength(self, A, B):
    A = bytes(A)
    B = bytes(B)
    for length in range(len(A) + 1):
        if not any(A[i:i+length] in B for i in range(len(A) - length + 1)):
            return length - 1
    return length
*/