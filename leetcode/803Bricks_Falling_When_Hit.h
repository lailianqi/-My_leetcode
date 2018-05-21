#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题写不出来 直接看的答案
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/119829/Python-Solution-by-reversely-adding-hits-bricks-back
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/121072/Java-Solution
class Solution {
  public:
    vector<int> hitBricks(vector<vector<int>> &grid,
                          vector<vector<int>> &hits) {
        int m = grid.size(), n = grid[0].size();
        int k = hits.size();
        for (int i = 0; i < k; i++) {
            grid[hits[i][0]][hits[i][1]] -= 1;
        }
        for (int j = 0; j < n; j++) {
            helper(grid, 0, j);
        }
        vector<int> res(k, 0);
        for (int j = k - 1; j >= 0; j--) {
            int row = hits[j][0], col = hits[j][1];
            grid[row][col] += 1;
            if (grid[row][col] == 1 && is_connect(grid, row, col)) {
                res[j] = helper(grid, row, col) - 1;
            }
        }
        return res;
    }
    int helper(vector<vector<int>> &grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (!(row >= 0 && row < m && col >= 0 && col < n) ||
            grid[row][col] != 1) {
            return 0;
        }
        int res = 1;
        grid[row][col] = 2;
        int d = direction.size();
        for (int i = 0; i < d; i++) {
            res += helper(grid, row + direction[i][0], col + direction[i][1]);
        }
        return res;
    }
    bool is_connect(vector<vector<int>> &grid, int row, int col) {
        if (row == 0) {
            return true;
        }
        int m = grid.size(), n = grid[0].size(), d = direction.size();
        for (int i = 0; i < d; i++) {
            int x = row + direction[i][0], y = col + direction[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 2) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

// 第二种方法 来自leetcode 比较暴力
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/120057/C++-DFS-(similar-to-LC749)

// 第三种解法 UnionFind解法 来自leetcode
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/121077/Java-Union-Find-by-backwardly-adding-bricks-back-20ms