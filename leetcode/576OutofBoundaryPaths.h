#include <stddef.h>
#include <vector>
using namespace std;
// 这道题没想出来  直接看的答案
// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/88674/clean-code-8-solutions-6-c-2-java
class Solution {
  public:
    int findPaths(int m, int n, int N, int i, int j) {
        size_t limit = 1000000007;
        vector<vector<vector<size_t>>> dp(
            N + 1, vector<vector<size_t>>(m, vector<size_t>(n, 0)));
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k][i][j] += i == 0 ? 1 : dp[k - 1][i - 1][j];
                    dp[k][i][j] += i == m - 1 ? 1 : dp[k - 1][i + 1][j];
                    dp[k][i][j] += j == 0 ? 1 : dp[k - 1][i][j - 1];
                    dp[k][i][j] += j == n - 1 ? 1 : dp[k - 1][i][j + 1];
                    dp[k][i][j] %= limit;
                }
            }
        }
        return dp[N][i][j];
    }
};

// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/88674/clean-code-8-solutions-6-c-2-java
class Solution_0 {
  public:
    int findPaths(int m, int n, int N, int i0, int j0) {
        vector<vector<vector<uint32_t>>> dp(
            N + 1, vector<vector<uint32_t>>(m, vector<uint32_t>(n, 0)));
        auto paths = [&](int k, int i, int j) {
            return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k][i][j];
        };
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k][i][j] =
                        paths(k - 1, i - 1, j) + paths(k - 1, i + 1, j) +
                        paths(k - 1, i, j - 1) + paths(k - 1, i, j + 1);
                    dp[k][i][j] %= 1000000007;
                }
            }
        }
        return dp[N][i0][j0];
    }
};

// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/88674/clean-code-8-solutions-6-c-2-java
class Solution_1 {
  public:
    int findPaths(int m, int n, int N, int i0, int j0) {
        vector<vector<vector<uint32_t>>> dp(
            2, vector<vector<uint32_t>>(m, vector<uint32_t>(n, 0)));
        auto paths = [&](int k, int i, int j) {
            return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k % 2][i][j];
        };
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k % 2][i][j] =
                        paths(k - 1, i - 1, j) + paths(k - 1, i + 1, j) +
                        paths(k - 1, i, j - 1) + paths(k - 1, i, j + 1);
                    dp[k % 2][i][j] %= 1000000007;
                }
            }
        }
        return dp[N % 2][i0][j0];
    }
};

// 这种写法太屌了 第一次看见c++也可以这样子写
// https://discuss.leetcode.com/topic/88674/clean-code-8-solutions-6-c-2-java/2
class Solution_2 {
  public:
    int findPaths(int m, int n, int N, int i0, int j0) {
        vector<vector<vector<uint32_t>>> dp(
            2, vector<vector<uint32_t>>(m, vector<uint32_t>(n, 0)));
        auto paths = [&](int k, int i, int j) -> uint32_t & {
            uint32_t one = 1;
            return (i < 0 || i >= m || j < 0 || j >= n) ? one : dp[k % 2][i][j];
        };
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    paths(k, i, j) =
                        paths(k - 1, i - 1, j) + paths(k - 1, i + 1, j) +
                        paths(k - 1, i, j - 1) + paths(k - 1, i, j + 1);
                    paths(k, i, j) %= 1000000007;
                }
            }
        }
        return paths(N, i0, j0);
    }
};