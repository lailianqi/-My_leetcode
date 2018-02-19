#include <vector>
using namespace std;
//简单题 成功ac
class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, counter = 0;
                for (int row : {-1, 0, 1}) {
                    for (int col : {-1, 0, 1}) {
                        if (validBound(M, i + row, j + col)) {
                            sum += M[i + row][j + col];
                            counter++;
                        }
                    }
                }
                result[i][j] = sum / counter;
            }
        }
        return result;
    }

    bool validBound(vector<vector<int>> &M, int x, int y) {
        int m = M.size(), n = M[0].size();
        if (x >= 0 && x < m && y >= 0 && y < n) {
            return true;
        }
        return false;
    }
};
