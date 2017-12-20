#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        vector<int> dp(m, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j] =
                    (j != 0 ? min(dp[j], dp[j - 1]) : dp[j]) + triangle[i][j];
            }
        }
        int minNum = INT_MAX;
        for (int j = 0; j < m; j++) {
            minNum = min(minNum, dp[j]);
        }
        return minNum;
    }
};
//非常小的改进版
class Solution_0 {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j] =
                    (j != 0 ? min(dp[j], dp[j - 1]) : dp[j]) + triangle[i][j];
            }
        }
        int minNum = INT_MAX;
        for (int j = 0; j < m; j++) {
            minNum = min(minNum, dp[j]);
        }
        return minNum;
    }
};