#include <algorithm>
#include <vector>
using namespace std;
// 下面是自己的第一种写法 成功ac
// LeetCode的答案和我的解法差不多 都是采用dfs的思想 写法也相近 不过
// 我的答案更加的简洁
// https://discuss.leetcode.com/topic/80802/java-solution-dfs-bfs/7
// https://discuss.leetcode.com/topic/80804/straight-forward-java-solution
class Solution {
  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        vector<vector<int>> dirction = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        helper(board, dirction, click[0], click[1]);
        return board;
    }
    void helper(vector<vector<char>> &board, vector<vector<int>> &dirction,
                int row, int col) {
        if (board[row][col] == 'E') {
            int m = board.size(), n = board[0].size();
            int mineNum = mineAroundNum(board, row, col);
            if (mineNum == 0) {
                board[row][col] = 'B';
                for (int i = 0; i < dirction.size(); i++) {
                    int x = row + dirction[i][0], y = col + dirction[i][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        helper(board, dirction, x, y);
                    }
                }
            } else {
                board[row][col] = '0' + mineNum;
            }
        }
    }
    int mineAroundNum(vector<vector<char>> &board, int row, int col) {
        int res = 0;
        int m = board.size(), n = board[0].size();
        for (int i = max(0, row - 1); i <= min(row + 1, m - 1); i++) {
            for (int j = max(0, col - 1); j <= min(col + 1, n - 1); j++) {
                if (board[i][j] == 'M') {
                    res++;
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<vector<char>> board = {{"E", "E", "E", "E", "E"},
                                  {"E", "E", "M", "E", "E"},
                                  {"E", "E", "E", "E", "E"},
                                  {"E", "E", "E", "E", "E"}};
    vector<int> &click = {3, 0};
    s.updateBoard(board, click);
}