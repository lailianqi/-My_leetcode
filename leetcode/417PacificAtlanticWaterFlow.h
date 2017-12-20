#include <vector>
#include <climits>
using namespace std;
//开始的时候题目都没有看懂 所以直接看的答案 惭愧
// leetcode的答案
// https://discuss.leetcode.com/topic/62379/java-bfs-dfs-from-ocean
//下面是答案中DFS的写法  当然还可以用BFS
class Solution {
  public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<pair<int, int>> res;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            helper(matrix, pacific, dir, i, 0, INT_MIN);
            helper(matrix, atlantic, dir, i, n - 1, INT_MIN);
        }
        for (int j = 0; j < n; j++) {
            helper(matrix, pacific, dir, 0, j, INT_MIN);
            helper(matrix, atlantic, dir, m - 1, j, INT_MIN);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back(make_pair(i, j));
                }
            }
        return res;
    }
    void helper(vector<vector<int>> &matrix, vector<vector<int>> &visited,
                vector<vector<int>> &dir, int x, int y, int height) {
        int m = matrix.size(), n = matrix[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            matrix[x][y] < height)
            return;
        visited[x][y] = true;
        for (int i = 0; i < dir.size(); i++) {
            int xx = x + dir[i][0], yy = y + dir[i][1];
            helper(matrix, visited, dir, xx, yy, matrix[x][y]);
        }
    }
};

// leetcode的解法 用bit替代visited的解法
// https://discuss.leetcode.com/topic/62314/very-concise-c-solution-using-dfs-and-bit-mask
class Solution_0 {
  public:
    vector<pair<int, int>> res;
    vector<vector<int>> visited;
    void dfs(vector<vector<int>> &matrix, int x, int y, int pre, int preval) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() ||
            matrix[x][y] < pre || (visited[x][y] & preval) == preval)
            return;
        visited[x][y] |= preval;
        if (visited[x][y] == 3)
            res.push_back({x, y});
        dfs(matrix, x + 1, y, matrix[x][y], visited[x][y]);
        dfs(matrix, x - 1, y, matrix[x][y], visited[x][y]);
        dfs(matrix, x, y + 1, matrix[x][y], visited[x][y]);
        dfs(matrix, x, y - 1, matrix[x][y], visited[x][y]);
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return res;
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n - 1, INT_MIN, 2);
        }
        for (int i = 0; i < n; i++) {
            dfs(matrix, 0, i, INT_MIN, 1);
            dfs(matrix, m - 1, i, INT_MIN, 2);
        }
        return res;
    }
};