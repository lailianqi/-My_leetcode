#include <vector>
using namespace std;

//自己的答案
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, 1));
        paths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                paths[0][j] = 0;
            else
                paths[0][j] = paths[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                paths[i][0] = 0;
            else
                paths[i][0] = paths[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    paths[i][j] = 0;
                else
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};

class Solution_0 {
  public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i-1][j-1] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

//节约空间的方案    https://discuss.leetcode.com/topic/10974/short-java-solution/10
/*
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int width = obstacleGrid[0].length;
    int[] dp = new int[width];
    dp[0] = 1;
    for (int[] row : obstacleGrid) {
        for (int j = 0; j < width; j++) {
            if (row[j] == 1)
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp[width - 1];
}*/