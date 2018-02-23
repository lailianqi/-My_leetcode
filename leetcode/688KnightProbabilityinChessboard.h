#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//自己的第一种解法 成功ac 采用了备忘录的解法 好题
class Solution {
  public:
    double knightProbability(int N, int K, int r, int c) {
        cost = vector<vector<vector<double>>>(
            K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
        return helper(N, K, r, c);
    }
    double helper(int N, int K, int r, int c) {
        if (r < 0 || c < 0 || r >= N || c >= N) {
            return 0;
        }
        if (K <= 0) {
            return 1;
        }
        if (cost[K][r][c] != -1) {
            return cost[K][r][c];
        }
        double res = 0, m = direction.size();
        for (int i = 0; i < direction.size(); i++) {
            res += 1.0 / m *
                   helper(N, K - 1, r + direction[i][0], c + direction[i][1]);
        }
        return cost[K][r][c] = res;
    }

  private:
    vector<vector<int>> direction = {{-2, 1}, {-2, -1}, {2, 1},  {2, -1},
                                     {1, 2},  {1, -2},  {-1, 2}, {-1, -2}};
    vector<vector<vector<double>>> cost;
};

// 来自LeetCode的答案 和上面的思想差不多 写法略有不同
// https://leetcode.com/problems/knight-probability-in-chessboard/discuss/108187/C++Java-DP-concise-solution
class Solution_0 {
  public:
    double knightProbability(int N, int K, int r, int c) {
        cost = vector<vector<vector<double>>>(
            K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
        return helper(N, K, r, c) / pow(8, K);
    }
    double helper(int N, int K, int r, int c) {
        if (r < 0 || c < 0 || r >= N || c >= N) {
            return 0;
        }
        if (K <= 0) {
            return 1;
        }
        if (cost[K][r][c] != -1) {
            return cost[K][r][c];
        }
        double res = 0, m = direction.size();
        for (int i = 0; i < direction.size(); i++) {
            res += helper(N, K - 1, r + direction[i][0], c + direction[i][1]);
        }
        return cost[K][r][c] = res;
    }

  private:
    vector<vector<int>> direction = {{-2, 1}, {-2, -1}, {2, 1},  {2, -1},
                                     {1, 2},  {1, -2},  {-1, 2}, {-1, -2}};
    vector<vector<vector<double>>> cost;
};

// dp的写法 参考LeetCode
// https://leetcode.com/problems/knight-probability-in-chessboard/discuss/108181/My-accepted-DP-solution
class Solution_1 {
  public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp = vector<vector<vector<double>>>(
            K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        for (int i = 0; i < N; i++) {
            fill_n(dp[0][i].begin(), N, 1);
        }
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto d : direction) {
                        int r = i + d[0], c = j + d[1];
                        if (isInBoundry(r, c, N)) {
                            dp[k][i][j] += dp[k - 1][r][c];
                        }
                    }
                }
            }
        }
        return dp[K][r][c] / pow(8, K);
    }
    bool isInBoundry(int r, int c, int N) {
        if (r < 0 || c < 0 || r >= N || c >= N) {
            return false;
        }
        return true;
    }

  private:
    vector<vector<int>> direction = {{-2, 1}, {-2, -1}, {2, 1},  {2, -1},
                                     {1, 2},  {1, -2},  {-1, 2}, {-1, -2}};
};

// sp大神python的写法
// https://leetcode.com/problems/knight-probability-in-chessboard/discuss/108193/Python

// 一个名校的学生
// https://leetcode.com/dancernight/