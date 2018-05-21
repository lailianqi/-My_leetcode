#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题一开始没看懂题意 直接看的答案 是一道拓扑排序的题目
// https://leetcode.com/problems/find-eventual-safe-states/description/
class Solution {
  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int m = graph.size();
        vector<int> color(m, 0);
        vector<int> res;
        for (int i = 0; i < m; i++) {
            if (helper(graph, color, i)) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool helper(vector<vector<int>> &graph, vector<int> &color, int index) {
        if (color[index] != 0) {
            return color[index] == 1;
        }
        color[index] = 2;
        for (int i = 0, m = graph[index].size(); i < m; i++) {
            if (!helper(graph, color, graph[index][i])) {
                return false;
            }
        }
        color[index] = 1;
        return true;
    }
};

// 另外的一种解法 用的拓扑排序的解法
// https://leetcode.com/problems/find-eventual-safe-states/discuss/119827/20-line-Python-concise-sol-by-removing-0-out-degree-nodes