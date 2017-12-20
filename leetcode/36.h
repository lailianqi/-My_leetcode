#include <vector>
using namespace std;
class Solution {
  public:
    bool isValidSudoku(vector<vector<char> > &board) {
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