#include <vector>
using namespace std;
//自己的写法
// leetcode的写法与此类似，下面是链接
// https://discuss.leetcode.com/topic/13248/very-concise-java-ac-solution?page=1
// https://discuss.leetcode.com/topic/20080/clear-easy-java-solution
// https://discuss.leetcode.com/topic/16749/7-lines-python-14-lines-java
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && grid[i][j] == '1') {
                    helper(i, j, visit, direction, grid);
                    res++;
                }
            }
        }
        return res;
    }
    void helper(int row, int col, vector<vector<bool>> &visit,
                vector<vector<int>> &direction, vector<vector<char>> &grid) {
        visit[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + direction[i][0];
            int newCol = col + direction[i][1];
            if (newRow >= 0 && newRow < visit.size() && newCol >= 0 &&
                newCol < visit[0].size() && !visit[newRow][newCol] &&
                grid[newRow][newCol] == '1') {
                helper(newRow, newCol, visit, direction, grid);
            }
        }
    }
};