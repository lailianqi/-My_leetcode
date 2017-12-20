#include <vector>
using namespace std;
//这个题目挺简单的 但是要符合要求
// 题目要求
// Could you do it in one-pass, using only O(1) extra memory and without
// modifying the value of the board?
//所以本题基本上不能用DFS的解法 要不然不符合要求
// leetcode 的解法
// https://discuss.leetcode.com/topic/62970/simple-java-solution
class Solution {
  public:
    int countBattleships(vector<vector<char>> &board) {
        int counter = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    if ((i == 0 || board[i - 1][j] != 'X') &&
                        (j == 0 || board[i][j - 1] != 'X')) {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};