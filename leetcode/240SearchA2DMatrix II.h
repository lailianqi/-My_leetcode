#include <vector>
using namespace std;
//这种解法存在超时
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> direction = {{1, 0}, {0, 1}};
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        return searchMatrix(matrix, visit, direction, 0, 0, target);
    }
    bool searchMatrix(vector<vector<int>> &matrix, vector<vector<bool>> &visit,
                      vector<vector<int>> &direction, int i, int j,
                      int target) {
        visit[i][j] = true;
        if (matrix[i][j] == target) {
            return true;
        }
        for (int t = 0; t < direction.size(); t++) {
            int row = i + direction[t][0];
            int col = j + direction[t][1];
            if (row >= 0 && row <= matrix.size() - 1 && col >= 0 &&
                col <= matrix[0].size() - 1) {
                if (!visit[row][col] && matrix[row][col] <= target &&
                    searchMatrix(matrix, visit, direction, row, col, target)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution_0 {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int row = 0, col = matrix[0].size() - 1;
        while (row <= matrix.size() - 1 && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

//下面是递归的修改版
class Solution_1 {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix[0].size();
        return searchMatrix(matrix, 0, n - 1, target);
    }
    bool searchMatrix(vector<vector<int>> &matrix, int i, int j, int target) {
        if (i >= matrix.size() || j < 0)
            return false;
        if (matrix[i][j] == target) {
            return true;
        }
        if (matrix[i][j] > target) {
            return searchMatrix(matrix, i, j - 1, target);
        }
        return searchMatrix(matrix, i + 1, j, target);
    }
};