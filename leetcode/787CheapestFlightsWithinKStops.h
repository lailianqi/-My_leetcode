#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// 72周周赛
// 没写出来 是因为是有向图
// 自己比赛中写的错误的解法 用作反思
class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int K) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> path(n, vector<int>(n, 1));
        for (int i = 0; i < flights.size(); i++) {
            dp[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i + 1; k < j; k++) {
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                        if (path[i][k] + path[k][j] <= K + 1) {
                            if (dp[i][k] + dp[k][j] < dp[i][j]) {
                                dp[i][j] = dp[i][k] + dp[k][j];
                                path[i][j] = path[i][k] + path[k][j];
                            }
                        }
                    }
                }
            }
        }
        return dp[src][dst] == INT_MAX ? -1 : dp[src][dst];
    }
};
//原来以为递归是可以的，后来发现限制了步数后 普通的递归是不可行的
//画图就可以知道为什么不可以
//如果用BFS也非常的麻烦 以为可能会回头更新旧数据 也非常的麻烦

// 来自LeetCode的解法 作者的首页在这里
// https://leetcode.com/fr0benius/
// 目前来看 这是最好的写法
class Solution_1 {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int K) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<int> dist(n, INT_MAX);
        for (int i = 0; i < flights.size(); i++) {
            int v = flights[i][0], w = flights[i][1], c = flights[i][2];
            dp[v][w] = c;
            if (v == src)
                dist[w] = c;
        }
        for (int k = 0; k < K; k++) {
            for (int v = 0; v < n; v++) {
                for (int w = 0; w < n; w++)
                    if (dp[w][v] != INT_MAX && dist[w] != INT_MAX) {
                        dist[v] = min(dist[v], dist[w] + dp[w][v]);
                    }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//上面的改写版
class Solution_11 {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int K) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<int> dist(n, INT_MAX);
        for (int i = 0; i < flights.size(); i++) {
            int v = flights[i][0], w = flights[i][1], c = flights[i][2];
            dp[v][w] = c;
        }
        for (int k = 0; k < K; k++) {
            for (int v = 0; v < n; v++) {
                for (int w = 0; w < n; w++)
                    if (dp[w][v] != INT_MAX && dp[src][w] != INT_MAX) {
                        dp[src][v] = min(dp[src][v], dp[src][w] + dp[w][v]);
                    }
            }
        }
        return dp[src][dst] == INT_MAX ? -1 : dp[src][dst];
    }
};

// 最经典的dp的写法 但是感觉解法有点毛病
// 来自LeetCode的答案
// https://leetcode.com/taobingxue/
class Solution_2 {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int K) {
        int MAXI = 1000000000;
        vector<vector<vector<int>>> res(
            n, vector<vector<int>>(n, vector<int>(n, MAXI)));
        int l = flights.size();
        for (int i = 0; i < l; ++i) {
            if (res[flights[i][0]][flights[i][1]][0] > flights[i][2]) {
                res[flights[i][0]][flights[i][1]][0] = flights[i][2];
            }
        }
        for (int k = 1; k <= K; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    res[i][j][k] = res[i][j][k - 1];
                    for (int p = 0; p < n; ++p) {
                        if (res[i][p][k - 1] + res[p][j][0] < res[i][j][k]) {
                            //感觉这里有点问题
                            res[i][j][k] = res[i][p][k - 1] + res[p][j][0];
                        }
                    }
                }

        if (res[src][dst][K] == MAXI)
            return -1;
        return res[src][dst][K];
    }
};
