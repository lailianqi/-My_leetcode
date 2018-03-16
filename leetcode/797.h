#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
// LeetCode上面的答案写的都非常的一般
// https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118829/C++-super-easy-solution!
// https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118647/C++-DFS-Recursive-Easy-to-Understand
class Solution {
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int m = graph.size();
        vector<bool> visited(m, false);
        vector<int> result = {0};
        helper(graph, visited, result, 0, m - 1);
        return results;
    }
    void helper(vector<vector<int>> &graph, vector<bool> &visited,
                vector<int> &result, int source, int destination) {
        if (source == destination) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < graph[source].size(); i++) {
            if (!visited[graph[source][i]]) {
                visited[graph[source][i]] = true;
                result.push_back(graph[source][i]);
                helper(graph, visited, result, graph[source][i], destination);
                result.pop_back();
                visited[graph[source][i]] = false;
            }
        }
    }

  private:
    vector<vector<int>> results;
};

void test() {
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    s.allPathsSourceTarget(graph);
}