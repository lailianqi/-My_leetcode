#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 直接看的答案 来自LeetCode的答案
// 暴力的解法 直接超时 解法来自LeetCode
// https://discuss.leetcode.com/topic/82720/evolve-from-brute-force-to-dp
class Solution {
  public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> pos(26, vector<int>());
        for (int i = 0; i < ring.size(); i++)
            pos[ring[i] - 'a'].push_back(i);
        return findSteps(0, 0, ring, key, pos);
    }
    int findSteps(int p1, int p2, string &ring, string &key,
                  vector<vector<int>> &pos) {
        if (p2 == key.size())
            return 0;
        int r = ring.size(), ms = INT_MAX;
        for (int nxt : pos[key[p2] - 'a']) {
            int dist = abs(p1 - nxt);
            ms = min(ms, min(dist, r - dist) +
                             findSteps(nxt, p2 + 1, ring, key, pos));
        }
        return ms + 1;
    }
};

// 备忘录的解法
// https://discuss.leetcode.com/topic/82720/evolve-from-brute-force-to-dp
class Solution_0 {
  public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> pos(26, vector<int>());
        for (int i = 0; i < ring.size(); i++)
            pos[ring[i] - 'a'].push_back(i);
        vector<vector<int>> mem(ring.size(), vector<int>(key.size()));
        return findSteps(0, 0, ring, key, pos, mem);
    }
    int findSteps(int p1, int p2, string &ring, string &key,
                  vector<vector<int>> &pos, vector<vector<int>> &mem) {
        if (p2 == key.size())
            return 0;
        if (mem[p1][p2])
            return mem[p1][p2];
        int r = ring.size(), ms = INT_MAX;
        for (int nxt : pos[key[p2] - 'a']) {
            int dist = abs(p1 - nxt);
            ms = min(ms, min(dist, r - dist) +
                             findSteps(nxt, p2 + 1, ring, key, pos, mem));
        }
        return mem[p1][p2] = ms + 1;
    }
};

// dp的写法
// 来自LeetCode
// https://discuss.leetcode.com/topic/82720/evolve-from-brute-force-to-dp
// https://discuss.leetcode.com/topic/81684/concise-java-dp-solution
class Solution_1 {
  public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> pos(26, vector<int>());
        int r = ring.size(), k = key.size();
        for (int i = 0; i < r; i++)
            pos[ring[i] - 'a'].push_back(i);
        vector<vector<int>> dp(k + 1, vector<int>(r, INT_MAX));
        dp[k].assign(r, 0);
        for (int i = k - 1; i >= 0; i--) {
            for (int j = 0; j < r; j++) {
                for (int nxt : pos[key[i] - 'a']) {
                    int dist = abs(j - nxt);
                    dp[i][j] =
                        min(dp[i][j], dp[i + 1][nxt] + min(dist, r - dist));
                }
            }
        }
        return dp[0][0] + k;
    }
};

// 最后一种 linear space dp
// https://discuss.leetcode.com/topic/82720/evolve-from-brute-force-to-dp
//..............................

//..............................

//自己看着答案改写的dp的写法
class Solution_2 {
  public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        vector<vector<int>> pos(26, vector<int>());
        for (int i = 0; i < n; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int index : pos[key[i] - 'a']) {
                    int dist = abs(j - index);
                    dp[i][j] = min(dp[i][j],
                                   min(dist, n - dist) + dp[i + 1][index] + 1);
                }
            }
        }
        return dp[0][0];
    }
};