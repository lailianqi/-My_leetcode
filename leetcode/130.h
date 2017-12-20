#include <vector>
#include <queue>
using namespace std;
//通不过极端情况的解法,因为递归导致栈溢出
class Solution {
  public:
    vector<vector<int>> step = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> maps;
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();
        maps = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    surroundedRegions(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!maps[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void surroundedRegions(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] == 'X' || maps[row][col])
            return;
        maps[row][col] = true;
        for (int i = 0; i < step.size(); i++) {
            int newRow = row + step[i][0];
            int newCol = col + step[i][1];
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 &&
                newCol < board[0].size()) //这个样子不行
                surroundedRegions(board, newRow, newCol);
        }
    }
};
//不算改进，就减少了一层递归，然后正好没有溢出，然后AC
class Solution_0 {
  public:
    vector<vector<int>> step = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> maps;
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();
        maps = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    surroundedRegions(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!maps[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void surroundedRegions(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] == 'X' || maps[row][col])
            return;
        maps[row][col] = true;
        for (int i = 0; i < step.size(); i++) {
            int newRow = row + step[i][0];
            int newCol = col + step[i][1];
            if (newRow > 0 && newRow < board.size() && newCol > 0 &&
                newCol < board[0].size())
                surroundedRegions(board, newRow, newCol);
        }
    }
};

// https://discuss.leetcode.com/topic/35407/20-ms-c-recommend-for-beginners-clean-c-implementation-with-detailed-explanation
// BFS的版本,参考后自己修改
class Solution_1 {
  public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        vector<vector<int>> step = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> pointQueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    board[i][j] == 'O') {
                    pointQueue.push(make_pair(i, j));
                }
            }
        }
        while (!pointQueue.empty()) {
            pair<int, int> point = pointQueue.front();
            pointQueue.pop();
            board[point.first][point.second] = 'N';
            for (int i = 0; i < step.size(); i++) {
                int newRow = point.first + step[i][0];
                int newCol = point.second + step[i][1];
                if (iSInboundary(m, n, newRow, newCol) &&
                    board[newRow][newCol] == 'O') {
                    pointQueue.push(make_pair(newRow, newCol));
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'N')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    bool iSInboundary(int m, int n, int row, int col) {
        if (row >= 0 && row < m && col >= 0 && col < n) {
            return true;
        }
        return false;
    }
};