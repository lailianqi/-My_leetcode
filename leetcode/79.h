#include <vector>
#include <string>
#include <iostream>
using namespace std;

//自己的答案  You are here!  Your runtime beats 74.13 % of cpp submissions.
// Runtime: 13 ms
class Solution {
  public:
    bool answer = false;
    bool exist(vector<string> &board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> map(m, vector<bool>(n, false));
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (answer)
                    return true;
                existTrack(board, map, word, direction, i, j, 0);
            }
        }
        return answer;
    }
    void existTrack(vector<string> &board, vector<vector<bool>> &map,
                    string &word, int direction[][2], int row, int col,
                    int deep) {
        int m = board.size(), n = board[0].size();
        if (answer ||
            (deep == word.size() - 1 && word[deep] == board[row][col])) {
            answer = true;
            return;
        }
        if (board[row][col] == word[deep]) {
            map[row][col] = true;
            for (int i = 0; i < 4; i++) {
                int newRow = row + direction[i][0];
                int newCol = col + direction[i][1];
                if (newRow >= 0 && newRow <= m - 1 && newCol >= 0 &&
                    newCol <= n - 1 && map[newRow][newCol] == false) {
                    existTrack(board, map, word, direction, newRow, newCol,
                               deep + 1);
                }
            }
            map[row][col] = false;
        }
    }
};
// Java的写法
/*
public boolean exist(char[][] board, String word) {
    char[] w = word.toCharArray();
    for (int y=0; y<board.length; y++) {
        for (int x=0; x<board[y].length; x++) {
                if (exist(board, y, x, w, 0)) return true;
        }
    }
    return false;
}

private boolean exist(char[][] board, int y, int x, char[] word, int i) {
        if (i == word.length) return true;
        if (y<0 || x<0 || y == board.length || x == board[y].length) return
false;
        if (board[y][x] != word[i]) return false;
        board[y][x] ^= 256;
        boolean exist = exist(board, y, x+1, word, i+1)
                || exist(board, y, x-1, word, i+1)
                || exist(board, y+1, x, word, i+1)
                || exist(board, y-1, x, word, i+1);
        board[y][x] ^= 256;
        return exist;
}
*/
//另外的C++写法，参考leetcode
//https://discuss.leetcode.com/topic/35833/recommend-for-beginners-clean-c-implementation-with-detailed-explanation/2
class Solution_0 {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() == 0)
            return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (help(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }

    bool help(vector<vector<char>> &board, int i, int j, int len, string word) {
        if (len == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[len] || board[i][j] == '*')
            return false;
        char ch = board[i][j];
        board[i][j] = '*';
        bool result = help(board, i + 1, j, len + 1, word) ||
                      help(board, i - 1, j, len + 1, word) ||
                      help(board, i, j + 1, len + 1, word) ||
                      help(board, i, j - 1, len + 1, word);
        board[i][j] = ch;
        return result;
    }
};

void test() {
    vector<string> board = {"ab"};
    string word = "ba";
    Solution s;
    bool flag = s.exist(board, word);
    if (flag) {
        cout << "ddddd" << endl;
    }
}