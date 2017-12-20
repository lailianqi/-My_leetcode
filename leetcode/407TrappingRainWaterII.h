#include <vector>
#include <queue>
using namespace std;
//现在的我写不出来
// leetcode的答案
// https://discuss.leetcode.com/topic/60418/java-solution-using-priorityqueue?page=1
// https://discuss.leetcode.com/topic/60914/concise-c-priority_queue-solution
class Solution {
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> que;
        int row = heightMap.size(), col = heightMap[0].size(), maxHeight = 0,
            res = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!(i == 0 || i == row - 1 || j == 0 || j == col - 1))
                    continue;
                que.push(make_pair(heightMap[i][j], i * col + j));
                visited[i][j] = 1;
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!que.empty()) {
            auto val = que.top();
            que.pop();
            int height = val.first, x = val.second / col, y = val.second % col;
            maxHeight = max(maxHeight, height);
            for (auto dir : dirs) {
                int x2 = x + dir[0], y2 = y + dir[1];
                if (x2 >= row || x2 < 0 || y2 < 0 || y2 >= col ||
                    visited[x2][y2])
                    continue;
                visited[x2][y2] = 1;
                if (heightMap[x2][y2] < maxHeight)
                    res += maxHeight - heightMap[x2][y2];
                que.push(make_pair(heightMap[x2][y2], x2 * col + y2));
            }
        }
        return res;
    }
};