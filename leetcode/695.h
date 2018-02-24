#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac
// LeetCode上面的解法和这个差不多一模一样
// https://leetcode.com/problems/max-area-of-island/discuss/108533/JavaC++-Straightforward-dfs-solution
// https://leetcode.com/problems/max-area-of-island/discuss/108580/JavaC++-Clean-Code
class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, helper(grid, i, j));
                }
            }
        }
        return res;
    }
    int helper(vector<vector<int>> &grid, int row, int col) {
        int res = 1;
        grid[row][col] = -1;
        for (int i = 0; i < direction.size(); i++) {
            int x = row + direction[i][0], y = col + direction[i][1];
            if (isInVaildBoardary(grid, x, y) && grid[x][y] == 1) {
                res += helper(grid, x, y);
            }
        }
        return res;
    }
    bool isInVaildBoardary(vector<vector<int>> &grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row >= 0 && row < m && col >= 0 && col < n) {
            return true;
        }
        return false;
    }

  private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

// leetcode python的解法
// https://leetcode.com/problems/max-area-of-island/discuss/108541/easy-python

// def maxAreaOfIsland(self, grid):
//         m, n = len(grid), len(grid[0])
//         def dfs(i, j):
//             if 0 <= i < m and 0 <= j < n and grid[i][j]:
//                 grid[i][j] = 0
//                 return 1 + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i + 1, j) +
//                 dfs(i, j - 1)
//             return 0
//         areas = [dfs(i, j) for i in range(m) for j in range(n) if grid[i][j]]
//         return max(areas) if areas else 0

// 另外一种python的写法 来自sp大神
// https://leetcode.com/problems/max-area-of-island/discuss/108565/4-lines
// def maxAreaOfIsland(self, grid):
//     grid = {i + j*1j: val for i, row in enumerate(grid) for j, val in enumerate(row)}
//     def area(z):
//         return grid.pop(z, 0) and 1 + sum(area(z + 1j**k) for k in range(4))
//     return max(map(area, set(grid)))