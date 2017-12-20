#include <vector>
#include <climits>
using namespace std;
//这个方案大错特错，该问题不能自底向上，下面是错误的做法，逻辑就错了
class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = 1;
        dp[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int need =
                    min(dp[i - 1][j], dp[i][j - 1]) - dungeon[i - 1][j - 1];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[m][n];
    }
};

class Solution_0 {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = 1;
        dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};
// https://discuss.leetcode.com/topic/6912/c-dp-solution/4
// https://discuss.leetcode.com/topic/19304/6-lines-16-ms-c-o-mn-time-o-n-space/5
class Solution_1 {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[j] = max(min(dp[j], dp[j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0];
    }
};

void test() {
    Solution s;
    vector<vector<int>> dungeon = {{0}};
    s.calculateMinimumHP(dungeon);
}