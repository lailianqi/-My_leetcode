#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// LeetCode第70周周赛
// 虽然这道题比赛中没有时间写 但是在比赛后自己独立做出来
// 自己的第一种方案 成功ac
// LeetCode上面 有一个人和我的第一种方案的思想一模一样 写法也差不多
// 下面是地址链接
// https://discuss.leetcode.com/topic/119478/java-dp-dfs

class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) {
        int m = grid.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        helper(grid, 0, 0, 0, dp);
        return dp[m - 1][m - 1];
    }
    void helper(vector<vector<int>> &grid, int row, int col, int deep,
                vector<vector<int>> &dp) {
        deep = max(deep, grid[row][col]);
        if (dp[row][col] <= deep) {
            return;
        }
        dp[row][col] = deep;
        int m = grid.size();
        for (int i = 0; i < direction.size(); i++) {
            int x = row + direction[i][0];
            int y = col + direction[i][1];
            if (x >= 0 && x < m && y >= 0 && y < m) {
                helper(grid, x, y, dp[row][col], dp);
            }
        }
    }

  private:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};

// 来自LeetCode二分查找的解法 思想也很牛逼 来自周赛排行榜的第四位
// https://leetcode.com/i_love_xiaoshagua_cpp/
class Solution_0 {
  private:
    bool canPass(vector<vector<int>> &grid, int t) {
        // whether can go from 0, 0 to N - 1, N - 1
        int N = grid.size();
        if (grid[0][0] > t)
            return false;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int, int>> frontier;
        frontier.push(pair<int, int>{0, 0});
        visited[0][0] = true;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!frontier.empty()) {
            pair<int, int> curr = frontier.front();
            frontier.pop();
            int i = curr.first, j = curr.second;
            if (i == N - 1 && j == N - 1)
                return true;
            for (auto dir : dirs) {
                int new_i = i + dir.first, new_j = j + dir.second;
                if (0 <= new_i && new_i < N && 0 <= new_j && new_j < N &&
                    !visited[new_i][new_j] && grid[new_i][new_j] <= t) {
                    visited[new_i][new_j] = true;
                    frontier.push(pair<int, int>{new_i, new_j});
                }
            }
        }
        return false;
    }

  public:
    int swimInWater(vector<vector<int>> &grid) {
        int N = grid.size();
        int lo = 1, hi = N * N;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (canPass(grid, mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};

// 来自LeetCode优先队列的解法 也非常的牛逼 这个方法是递归和优先队列结合
// 当然也可以直接迭代的方法使用优先队列而不用递归
// https://discuss.leetcode.com/topic/119497/18ms-java-backtracking
void test() {
    Solution s;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    s.swimInWater(grid);
}