#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题现在的水平肯定写不出来 直接看的答案
// https://www.cnblogs.com/ctrlzhang/p/7998779.html
// https://www.cnblogs.com/grandyang/p/8215787.html
// https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
// https://leetcode.com/problems/cherry-pickup/discuss/109906/Annotated-C++-DP-Solution

//这个递归式子好牛逼
/*
T(i, j, p, q) = grid[i][j] + grid[p][q] + max{T(i-1, j, p-1, q), T(i-1, j, p,
q-1), T(i, j-1, p-1, q), T(i, j-1, p, q-1)}

T(n, i, p) = grid[i][n-i] + grid[p][n-p] + max{T(n-1, i-1, p-1), T(n-1, i-1, p),
T(n-1, i, p-1), T(n-1, i, p)}
*/
class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int N = grid.size(), M = (N << 1) - 1;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        dp[0][0] = grid[0][0];
        for (int n = 1; n < M; n++) {
            for (int i = N - 1; i >= 0; i--) {
                for (int p = N - 1; p >= 0; p--) {
                    int j = n - i, q = n - p;
                    if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 ||
                        grid[p][q] < 0) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0)
                        dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0)
                        dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0)
                        dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0)
                        dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }
        return max(dp[N - 1][N - 1], 0);
    }
};

// 更加容易懂的版本 下面的代码是直接抄LeetCode的论坛的  这题我还没完全搞定
// 以后有机会再看
// https://leetcode.com/problems/cherry-pickup/discuss/109906/Annotated-C++-DP-Solution
class Solution_0 {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        // dp holds maximum # of cherries two k-length paths can pickup.
        // The two k-length paths arrive at (i, k - i) and (j, k - j),
        // respectively.
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0]; // length k = 0
        // maxK: number of steps from (0, 0) to (n-1, n-1).
        const int maxK = 2 * (n - 1);
        for (int k = 1; k <= maxK; k++) { // for every length k
            vector<vector<int>> curr(n, vector<int>(n, -1));
            // one path of length k arrive at (i, k - i)
            for (int i = 0; i < n && i <= k; i++) {
                if (k - i >= n)
                    continue;
                // another path of length k arrive at (j, k - j)
                for (int j = 0; j < n && j <= k; j++) {
                    if (k - j >= n)
                        continue;
                    if (grid[i][k - i] < 0 ||
                        grid[j][k - j] < 0) { // keep away from thorns
                        continue;
                    }
                    int cherries = dp[i][j]; // # of cherries picked up by the
                                             // two (k-1)-length paths.
                    // See the figure below for an intuitive understanding
                    if (i > 0)
                        cherries = std::max(cherries, dp[i - 1][j]);
                    if (j > 0)
                        cherries = std::max(cherries, dp[i][j - 1]);
                    if (i > 0 && j > 0)
                        cherries = std::max(cherries, dp[i - 1][j - 1]);
                    // No viable way to arrive at (i, k - i)-(j, k-j).
                    if (cherries < 0)
                        continue;
                    // Pickup cherries at (i, k - i) and (j, k -j ) if i != j.
                    // Otherwise, pickup (i, k-i).
                    cherries += grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
                    curr[i][j] = cherries;
                }
            }
            dp = std::move(curr);
        }
        return std::max(dp[n - 1][n - 1], 0);
    }
};