#include <vector>
using namespace std;
/**
You are here!
Your runtime beats 1.82 % of cpp submissions.
*/
//参照答案做的
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> answer;
        if (matrix.size() == 0)
            return answer;
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0,
            colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++) {
                answer.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;
            for (int i = rowBegin; i <= rowEnd; i++) {
                answer.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if (rowBegin <= rowEnd) {
                for (int j = colEnd; j >= colBegin; j--) {
                    answer.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;
            }
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    answer.push_back(matrix[i][colBegin]);
                }
                colBegin++;
            }
        }
        return answer;
    }
};
/**
https://leetcode.com/problems/spiral-matrix/#/solutions
When traversing the matrix in the spiral order, at any time we follow one out of
the following four directions: RIGHT DOWN LEFT UP. Suppose we are working on a 5
x 3 matrix as such:

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15

Imagine a cursor starts off at (0, -1), i.e. the position at '0', then we can
achieve the spiral order by doing the following:

Go right 5 times
Go down 2 times
Go left 4 times
Go up 1 times.
Go right 3 times
Go down 0 times -> quit
Notice that the directions we choose always follow the order
'right->down->left->up', and for horizontal movements, the number of shifts
follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}.

Thus, we can make use of a direction matrix that records the offset for all
directions, then an array of two elements that stores the number of shifts for
horizontal and vertical movements, respectively. This way, we really just need
one for loop instead of four.

Another good thing about this implementation is that: If later we decided to do
spiral traversal on a different direction (e.g. Counterclockwise), then we only
need to change the Direction matrix; the main loop does not need to be touched.
*/
class Solution_0 {
  public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> answer;
        if (matrix.size() == 0)
            return answer;
        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> steps = {matrix[0].size(), matrix.size()-1};
        int idir = 0;
        int h = 0, v = -1;
        while (steps[idir % 2]) {
            for (int i = 0; i < steps[idir % 2]; i++) {
                h += dirs[idir][0];
                v += dirs[idir][1];
                answer.push_back(matrix[h][v]);
            }
            steps[idir % 2]--;
            idir = (idir + 1) % 4;
        }
        return answer;
    }
};

//https://leetcode.com/problems/spiral-matrix/#/solutions  Python的写法



// void test() {
//     Solution s;
//     vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     s.spiralOrder(v);
// }