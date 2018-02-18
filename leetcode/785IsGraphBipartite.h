#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 72周周赛
// 没写出来

//没写出来是正常的 这题是一个二分图问题
//这里是参加比赛时自己的错误解法
class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int m = graph.size(), res = 0;
        vector<bool> visited(graph.size(), false);
        for (int i = 0; i < m; i++) {
            if (!visited[i]) {
                helper(graph, i, visited);
                res++;
            }
        }
        return res == 2;
    }
    void helper(vector<vector<int>> &graph, int id, vector<bool> &visited) {
        if (visited[id]) {
            return;
        }
        visited[id] = true;
        for (int i = 0; i < graph[id].size(); i++) {
            if (!visited[graph[id][i]]) {
                helper(graph, graph[id][i], visited);
            }
        }
    }
};

// 来自LeetCode的答案 最基本的二分图的算法 交叉染色法
// https://discuss.leetcode.com/topic/120559/java-dfs
// 中文解释
// https://www.cnblogs.com/digitalhermit/p/5119908.html
// https://www.cnblogs.com/zhangjiuding/p/7710811.html
class Solution_0 {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int m = graph.size(), res = 0;
        vector<int> visited(graph.size(), 0);
        for (int i = 0; i < m; i++) {
            if (!visited[i] && !helper(graph, i, visited, 1)) {
                return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<int>> &graph, int id, vector<int> &visited,
                int color) {
        visited[id] = color;
        for (int i = 0; i < graph[id].size(); i++) {
            if (visited[graph[id][i]] == color) {
                return false;
            }
            if (visited[graph[id][i]] == 0 &&
                !helper(graph, graph[id][i], visited, -color)) {
                return false;
            }
        }
        return true;
    }
};
void test() {
    Solution s;
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    s.isBipartite(graph);
}