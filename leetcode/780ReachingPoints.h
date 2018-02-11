#include <vector>
using namespace std;
// 71周比赛 这题没过ac
class Solution {
  public:
    // 这种解法 内存超出了 根本没办法过
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) {
            return false;
        }
        vector<vector<bool>> dp(tx + 1, vector<bool>(ty + 1, false));
        dp[sx][sy] = true;
        for (int i = sx; i <= tx; i++) {
            for (int j = sy; j <= ty; j++) {
                if ((i + j <= tx || i + j <= ty) && dp[i][j]) {
                    if (i + j <= tx) {
                        dp[i + j][j] = true;
                    }
                    if (i + j <= ty) {
                        dp[i][i + j] = true;
                    }
                }
            }
        }
        return dp[tx][ty];
    }

    //这一种是暴力  绝对过不去的
    bool helper(int sx, int sy, int tx, int ty) {
        if ((sx == tx && sy == ty)) {
            return true;
        }
        if (sx > tx || sy > ty) {
            return false;
        }
        if (helper(sx, sy + sx, tx, ty) || helper(sx + sy, sy, tx, ty)) {
            return true;
        }
        return false;
    }
};

// 来自LeetCode的答案
// 官方题解 Time Complexity: O(max(tx, ty))O(max(tx,ty)). If say ty = 1, we
// could be subtracting tx times. oj上会超时
// https://leetcode.com/articles/reaching-points/
class Solution_0 {
  public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) {
                return true;
            }
            if (tx > ty) {
                tx = tx - ty;
            } else {
                ty = ty - tx;
            }
        }
        return false;
    }
};

// 来自LeetCode的答案
// 官方题解
// https://leetcode.com/articles/reaching-points/
// (19, 12) (7, 12) (7, 5),(2, 5)
class Solution_1 {
  public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) {
                break;
            }
            if (tx > ty) {
                if (ty > sy) { // 首先 ty > sy
                    tx %= ty;
                } else { // ty == sy
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) {
                    ty %= tx;
                } else { // tx==sx
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return (tx == sx && ty == sy);
    }
};

// 自己的理解 改造自LeetCode 结合上面的答案
// https://discuss.leetcode.com/topic/120286/c-simple-iterative
class Solution_2 {
  public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) {
                    return (tx - sx) % ty == 0;
                } else {
                    tx %= ty;
                }
            } else {
                if (tx == sx) {
                    return (ty - sy) % tx == 0;
                } else {
                    ty %= tx;
                }
            }
        }
        return false;
    }
};