#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
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
    int encode(vector<vector<int>> &board) { //为了hash的使用 encode
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

// 更加短的解法 超级的牛逼 来自LeetCode
// https://discuss.leetcode.com/topic/118726/c-9-lines-dfs-with-pruning
class Solution_1 {

  public:
    int slidingPuzzle(vector<vector<int>> &board) {
        string s = to_string(board[0][0]) + to_string(board[0][1]) +
                   to_string(board[0][2]) + to_string(board[1][0]) +
                   to_string(board[1][1]) + to_string(board[1][2]);
        helper(s, unordered_map<string, int>() = {}, s.find('0'), s.find('0'),
               0);
        return min_moves == INT_MAX ? -1 : min_moves;
    }
    void helper(string s, unordered_map<string, int> &m, int cur_zero,
                int swap_zero, int cur_move) {
        swap(s[cur_zero], s[swap_zero]);
        if (s == "123450")
            min_moves = min(min_moves, cur_move);
        if (cur_move < min_moves && (m[s] > cur_move || m[s] == 0)) {
            m[s] = cur_move;
            for (auto new_zero : moves[swap_zero]) {
                helper(s, m, swap_zero, new_zero, cur_move + 1);
            }
        }
    }

  private:
    unordered_map<int, vector<int>> moves{
        {0, {1, 3}},    {1, {0, 2, 4}}, {2, {1, 5}}, {3, {0, 4}},
        {4, {3, 5, 1}}, {5, {4, 2}}}; //字符串变成一维是需要走的位置
    int min_moves = INT_MAX;
};