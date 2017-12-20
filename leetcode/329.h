#include <vector>
#include <algorithm>
using namespace std;
/*
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
*/
// Your runtime beats 72.32 % of cpp submissions.
//未有任何的参考 自己写的答案 成功把困难题攻克了
class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> value(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, helper(matrix, directions, value, i, j));
            }
        }
        return result;
    }
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &directions,
               vector<vector<int>> &value, int i, int j) {
        if (value[i][j] != 0) {
            return value[i][j];
        }
        int result = 1;
        for (int k = 0; k < directions.size(); k++) {
            int row = i + directions[k][0], col = j + directions[k][1];
            if (isInBorder(matrix, row, col) &&
                matrix[row][col] < matrix[i][j]) {
                result = max(result,
                             helper(matrix, directions, value, row, col) + 1);
            }
        }
        value[i][j] = result;
        return result;
    }
    bool isInBorder(vector<vector<int>> &matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return false;
        }
        return true;
    }
};