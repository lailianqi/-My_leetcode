#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> paths(m + 1, vector<int>(n + 1, INT_MAX));
        paths[0][1] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                paths[i][j] =
                    min(paths[i - 1][j], paths[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return paths[m][n];
    }
};

void test() {
    Solution s;
    vector<vector<int>> grid = {{1, 2}, {1, 1}};
    cout << s.minPathSum(grid);
}