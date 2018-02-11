#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
// 71周比赛 这题没过ac
// 超出了我的目前的能力的范围

// 官方题解的答案
// https://leetcode.com/articles/transform-to-chessboard/
class Solution {
  public:
    int movesToChessboard(vector<vector<int>> &board) {
        int N = board.size();
        unordered_map<int, int> dir;
        for (int i = 0; i < N; i++) {
            int code = 0;
            for (int j = 0; j < N; j++) {
                code = 2 * code + board[i][j];
            }
            dir[code]++;
        }
        int k1 = analyzeCount(dir, N);
        if (k1 == -1)
            return -1;
        dir.clear();
        for (int c = 0; c < N; ++c) {
            int code = 0;
            for (int r = 0; r < N; ++r)
                code = 2 * code + board[r][c];
            dir[code]++;
        }

        int k2 = analyzeCount(dir, N);
        return k2 >= 0 ? k1 + k2 : -1;
    }
    int analyzeCount(unordered_map<int, int> &dir, int N) {
        if (dir.size() != 2) {
            return -1;
        }
        auto it = dir.begin();
        int k1 = it->first, k2 = (++it)->first;
        if (!(dir[k1] == N / 2 && dir[k2] == (N + 1) / 2) &&
            !(dir[k2] == N / 2 && dir[k1] == (N + 1) / 2))
            return -1;
        if ((k1 ^ k2) != (1 << N) - 1)
            return -1;
        int Nones = (1 << N) - 1;
        int ones = countInteger(k1 & Nones);
        int cand = INT_MAX;
        if (N % 2 == 0 || ones * 2 < N) { // zero start
            cand = min(cand, countInteger(k1 ^ (0xAAAAAAAA) & Nones) /
                                 2); //因为数字是从右边开始比较的 所以是1010
        }
        if (N % 2 == 0 || ones * 2 > N) // ones start
            cand = min(cand, countInteger(k1 ^ (0x55555555) & Nones) /
                                 2); //和上面同一个道理
        return cand;
    }
    int countInteger(int num) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (num & 1) {
                res++;
            }
            num >>= 1;
        }
        return res;
    }
};