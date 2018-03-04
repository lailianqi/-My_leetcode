#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 74周周赛 未参加
// 这题没看懂 没做出来 先放着
// 现在终于看懂了题目了
// 答案来自LeetCode的官方题解
// https://leetcode.com/articles/valid-tic-tac-toe-state/
// 第二个链接的答案其实和题解差不多
// https://leetcode.com/problems/valid-tic-tac-toe-state/discuss/117592/Simple-Python-Solution-with-explanation
class Solution {
  public:
    bool validTicTacToe(vector<string> &board) {
        int xCount = 0, oCount = 0;
        for (string row : board) {
            for (char c : row) {
                if (c == 'X') {
                    xCount++;
                }
                if (c == 'O') {
                    oCount++;
                }
            }
        }
        if (oCount != xCount && oCount != xCount - 1) {
            return false;
        }
        if (isWin(board, 'X') && oCount != xCount - 1) {
            return false;
        }
        if (isWin(board, 'O') && oCount != xCount) {
            return false;
        }
        return true;
    }
    bool isWin(vector<string> &board, char p) {
        for (int i = 0; i < 3; i++) {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) {
                return true;
            }
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) {
                return true;
            }
        }
        if (board[0][0] == p && board[1][1] == p && board[2][2] == p) {
            return true;
        }
        if (board[0][2] == p && board[1][1] == p && board[2][0] == p) {
            return true;
        }
        return false;
    }
};