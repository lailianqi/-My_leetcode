#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

// 这题还是看了leetcode的答案 因为没有想到可以用路径的问题来求解
// https://discuss.leetcode.com/topic/83453/java-solution-bfs
class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> que;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = INT_MAX;
                } else {
                    que.push(pair<int, int>(i, j));
                }
            }
        }
        while (!que.empty()) {
            auto element = que.front();
            que.pop();
            for (int i = 0; i < dir.size(); i++) {
                int x = element.first + dir[i][0],
                    y = element.second + dir[i][1];
                if (isVaildBoundary(matrix, x, y) &&
                    (matrix[x][y] >
                     matrix[element.first][element.second] + 1)) {
                    que.push(pair<int, int>(x, y));
                    matrix[x][y] = matrix[element.first][element.second] + 1;
                }
            }
        }
        return matrix;
    }
    bool isVaildBoundary(vector<vector<int>> &matrix, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }
};

// 另外的一种方案
// https://discuss.leetcode.com/topic/83558/java-33ms-solution-with-two-sweeps-in-o-n
// 这种方案的第二个链接来自sp大神
// https://discuss.leetcode.com/topic/83558/java-33ms-solution-with-two-sweeps-in-o-n/4