#include <vector>
using namespace std;
//没有想出来
// leetcode的答案
// http://www.cnblogs.com/grandyang/p/4854466.html
// https://discuss.leetcode.com/topic/29054/easiest-java-solution-with-explanation/2
class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = liveNeighbors(board, i, j);
                if (board[i][j] == 1 && lives >= 2 && lives <= 3) {
                    board[i][j] = 3;
                }
                if (board[i][j] == 0 && lives == 3) {
                    board[i][j] = 2; // Make the 2nd bit 1: 00 ---> 10
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1; // Get the 2nd state.
            }
        }
    }
    int liveNeighbors(vector<vector<int>> &board, int row, int col) {
        int m = board.size(), n = board[0].size(), res = 0;
        for (int i = max(row - 1, 0); i <= min(row + 1, m - 1); i++) {
            for (int j = max(col - 1, 0); j <= min(col + 1, n - 1); j++) {
                res += board[i][j] & 1;
            }
        }
        // res-=board[row][col] & 1;
        // return res;
        return res - (board[row][col] & 1);
    }
};

//另外的答案 写的更简洁
// https://discuss.leetcode.com/topic/26112/c-o-1-space-o-mn-time

class Solution_0 {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, m); ++I)
                    for (int J = max(j - 1, 0); J < min(j + 2, n); ++J)
                        count += board[I][J] & 1;
                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};