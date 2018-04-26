#include <set>
#include <vector>
using namespace std;

// 第二遍刷的时候添加第一遍未添加的题解的链接
// https://leetcode.com/problems/valid-sudoku/discuss/15450/Shared-my-concise-Java-code
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool rows[9][9] = {false};     //检查行
        bool columns[9][9] = {false};  //检查列
        bool substock[9][9] = {false}; //检查所在块
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (rows[i][num] || columns[j][num] || substock[k][num]) {
                        return false;
                    }
                    rows[i][num] = columns[j][num] = substock[k][num] = true;
                }
            }
        }
        return true;
    }
};

// 第二种解法
// https://www.nowcoder.com/questionTerminal/8240bcdab4eb496fb6c4ba634fc67921
// https://leetcode.com/problems/valid-sudoku/discuss/15450/Shared-my-concise-Java-code?page=2
/**
 * 题意：让你判断这是否是一个正确的数独，
 * 即确定每一行，每一列以及每一个九宫格是否有相同的数字
 * HashSet的add方法，当添加成功（即set中不含有该元素）返回true
 */

class Solution_0 {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            set<char> rows, cols, cube;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !rows.insert(board[i][j]).second) {
                    return false;
                }
                if (board[j][i] != '.' && !cols.insert(board[j][i]).second) {
                    return false;
                }
                int cubeRow = 3 * (i / 3) + j / 3;
                int cubeCol = 3 * (i % 3) + j % 3;
                if (board[cubeRow][cubeCol] != '.' &&
                    !cube.insert(board[cubeRow][cubeCol]).second) {
                    return false;
                }
            }
        }
        return true;
    }
};