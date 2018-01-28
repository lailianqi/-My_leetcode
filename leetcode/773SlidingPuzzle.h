#include <map>
#include <vector>
using namespace std;
// 第69周的周赛
// 没写出来
// 来自LeetCode的答案 采用了A*的解法
// https://discuss.leetcode.com/topic/118671/simple-python-solution-using-a-search
// https://discuss.leetcode.com/topic/118671/simple-python-solution-using-a-search/2
class Solution {
  public:
    int slidingPuzzle(vector<vector<int>> &board) {}
};
// leetcode上另外一种好的解法 最基础的dfs的解法 比上面直观多了
// https://discuss.leetcode.com/topic/118732/java-intuitive-dfs-backtracking
class Solution_0 {

  public:
    int slidingPuzzle(vector<vector<int>> &board) {

        dic[123450] = 0;
        pair<int, int> zero;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    zero.first = i;
                    zero.second = j;
                    break;
                }
            }
        }
        helper(board, zero.first, zero.second, 0);
        return min_move == INT_MAX ? -1 : min_move;
    }
    void helper(vector<vector<int>> &board, int x, int y, int move) {
        if (move > min_move) {
            return;
        }
        int code = encode(board);
        if (code == 123450) {
            min_move = move;
            return;
        }
        if (dic.count(code) && move > dic[code]) {
            return;
        }
        dic[code] = move;
        for (auto element : dir) {
            int nx = x + element[0], ny = y + element[1];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                swap(board[x][y], board[nx][ny]);
                helper(board, nx, ny, move + 1);
                swap(board[x][y], board[nx][ny]);
            }
        }
    }
    int encode(vector<vector<int>> &board) {
        int code = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                code *= 10;
                code += board[i][j];
            }
        }
        return code;
    }

  private:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int min_move = INT_MAX;
    map<int, int> dic;
};