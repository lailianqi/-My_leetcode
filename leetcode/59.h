#include <vector>
using namespace std;

// You are here! Your runtime beats 0.40 % of cpp submissions
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n == 0)
            return matrix;
        spiralOrder(matrix);
        return matrix;
    }
    void spiralOrder(vector<vector<int>> &matrix) {
        int counter = 1;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> steps = {matrix[0].size(), matrix.size() - 1};
        int idir = 0;
        int h = 0, v = -1;
        while (steps[idir % 2]) {
            for (int i = 0; i < steps[idir % 2]; i++) {
                h += dirs[idir][0];
                v += dirs[idir][1];
                matrix[h][v] = counter++;
            }
            steps[idir % 2]--;
            idir = (idir + 1) % 4;
        }
    }
};

class Solution_0 {
  public:
    vector<vector<int> > generateMatrix(int x) {
        vector<vector<int> > my2DVector(x, vector<int>(x, 0));
        int number = 1;
        int m = my2DVector.size();
        for (int i = 0; i <= m / 2; i++) {
            for (int j = i; j < m - i; j++) // left -->right
                my2DVector[i][j] = number++;
            for (int j = i + 1; j < m - i; j++) // up --> down
                my2DVector[j][m - i - 1] = number++;
            for (int j = m - i - 2; j >= i; j--) // right --> left
                my2DVector[m - i - 1][j] = number++;
            for (int j = m - i - 2; j >= i + 1; j--) // down --> up
                my2DVector[j][i] = number++;
        }
        return my2DVector;
    }
};