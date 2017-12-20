#include <vector>
using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        double result = 1;
        int k = m - 1;
        int t = m + n - 2;
        for (int i = 1; i <= k; i++) {
            result = result * (t - k + i) / i;
        }
        return result;
    }
};

class Solution_0 {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > paths(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};