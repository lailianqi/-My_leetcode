#include <vector>
#include <cstring>
using namespace std;
//Solution_0 和 Solution2应该是一样的，实际情况是一个快，一个慢


class Solution {
  public:
    //题解代码
    void solveSudoku(vector<vector<char> > &board) { solve(board); }
    bool solve(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char> > &board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.' && board[i][col] == c)
                return false;
            if (board[row][i] != '.' && board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};
// My idea
class Solution_0 {
  public:
    bool rows[9][9] = {false};     //检查行
    bool columns[9][9] = {false};  //检查列
    bool substock[9][9] = {false}; //检查所在块
    //题解代码
    void solveSudoku(vector<vector<char> > &board) {
         isValidSudoku(board);
         solve(board);
    }
    bool solve(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            int k = i / 3 * 3 + j / 3;
                            int num = c - '0' - 1;
                            rows[i][num] = columns[j][num] = substock[k][num] = true;
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else{
                                board[i][j] = '.';
                                rows[i][num] = columns[j][num] = substock[k][num] = false;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char> > &board, int row, int col, char c){
        int k = row / 3 * 3 + col / 3;
        int num = c - '0' - 1;
        if(!rows[row][num] && !columns[col][num] && !substock[k][num]) {
            return true;
        }
        else
            return false;

    }
    void isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    rows[i][num] = columns[j][num] = substock[k][num] = true;
                }
            }
        }
    }
};

class Solution1 {
  public:
    bool check(vector<vector<char> > &board, int i, int j, char val) {
        int row = i - i % 3, column = j - j % 3;
        for (int x = 0; x < 9; x++)
            if (board[x][j] == val)
                return false;
        for (int y = 0; y < 9; y++)
            if (board[i][y] == val)
                return false;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[row + x][column + y] == val)
                    return false;
        return true;
    }
    bool solveSudoku(vector<vector<char> > &board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.')
            return solveSudoku(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
};

class Solution2 {
  public:
    bool col[10][10], row[10][10], f[10][10];
    bool flag = false;
    void solveSudoku(vector<vector<char> > &board) {
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(f, false, sizeof(f));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int temp = 3 * (i / 3) + j / 3;
                int num = board[i][j] - '0';
                col[j][num] = row[i][num] = f[temp][num] = true;
            }
        }
        dfs(board, 0, 0);
    }
    void dfs(vector<vector<char> > &board, int i, int j) {
        if (flag == true)
            return;
        if (i >= 9) {
            flag = true;
            return;
        }
        if (board[i][j] != '.') {
            if (j < 8)
                dfs(board, i, j + 1);
            else
                dfs(board, i + 1, 0);
            if (flag)
                return;
        }

        else {
            int temp = 3 * (i / 3) + j / 3;
            for (int n = 1; n <= 9; n++) {
                if (!col[j][n] && !row[i][n] && !f[temp][n]) {
                    board[i][j] = n + '0';
                    col[j][n] = row[i][n] = f[temp][n] = true;
                    if (j < 8)
                        dfs(board, i, j + 1);
                    else
                        dfs(board, i + 1, 0);
                    col[j][n] = row[i][n] = f[temp][n] = false;
                    if (flag)
                        return;
                }
            }
            board[i][j] = '.';
        }
    }
};