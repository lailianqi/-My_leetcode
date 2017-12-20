#include <vector>
using namespace std;
//自己的答案
// Your runtime beats 59.76 % of cpp submissions.
class NumMatrix {
  public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        result = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = (j == 0 ? 0 : result[i][j - 1]) + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += result[i][col2] - (col1 == 0 ? 0 : result[i][col1 - 1]);
        }
        return sum;
    }

  private:
    vector<vector<int>> result;
};
// leetcode的答案，时间的复杂的为o(1)
// https://discuss.leetcode.com/topic/29536/clean-c-solution-and-explaination-o-mn-space-with-o-1-time
class Solution {
  public:
    class NumMatrix {
      public:
        NumMatrix(vector<vector<int>> matrix) {
            int m = matrix.size();
            int n = m > 0 ? matrix[0].size() : 0;
            result = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    result[i][j] = result[i][j - 1] + result[i - 1][j] -
                                   result[i - 1][j - 1] + matrix[i - 1][j - 1];
                }
            }
        }
        int sumRegion(int row1, int col1, int row2, int col2) {
            return result[row2 + 1][col2 + 1] - result[row2 + 1][col1] -
                   result[row1][col2 + 1] + result[row1][col1];
        }

      private:
        vector<vector<int>> result;
    };
};

//这个leetcode的写法比较奇特
// https://discuss.leetcode.com/topic/29401/c-with-helper