#include <bits/stdc++.h>
using namespace std;

// 自己没写出来 看的答案
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/135686/Java-DP-Solution
class Solution {
  public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int m = graph.size();
        vector<vector<int>> dp(m, vector<int>(1 << m, INT_MAX));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            dp[i][1 << i] = 0;
            que.push(make_pair(i, 1 << i));
        }
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            for (auto next : graph[it.first]) {
                int nextMask = it.second | 1 << next;
                if (dp[next][nextMask] > dp[it.first][it.second] + 1) {
                    dp[next][nextMask] = dp[it.first][it.second] + 1;
                    que.push(make_pair(next, nextMask));
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            res = min(res, dp[i][(1 << m) - 1]);
        }
        return res;
    }
};