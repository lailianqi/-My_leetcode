#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// 这题没写出来 Dijkstra算法有点忘了 看了来自LeetCode的答案
// Dijkstra's Algorithm
// https://leetcode.com/problems/network-delay-time/discuss/109968/Simple-JAVA-Djikstra's-(PriorityQueue-optimized)-Solution-with-explanation
// https://leetcode.com/problems/network-delay-time/discuss/109970/JAVA-Djikstra's-Solution
// 下面的这种实现的方法 用了队列的方法 和传统的稍微显的不一样
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        auto graph = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
        vector<bool> visited(N + 1, false);
        for (int i = 0; i < times.size(); i++) {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        visited[0] = true, visited[K] = true;
        auto comp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            minStack(comp);
        for (int i = 0; i <= N; i++) {
            if (graph[K][i] >= 0) {
                minStack.push({i, graph[K][i]});
            }
        }
        int res = 0;
        while (!minStack.empty()) {
            auto current = minStack.top();
            minStack.pop();
            int target = current.first;
            if (visited[target]) {
                continue;
            }
            res = max(res, current.second);
            visited[target] = true;
            for (int i = 0; i <= N; i++) {
                if (!visited[i] && graph[target][i] >= 0) {
                    minStack.push(
                        make_pair(i, current.second + graph[target][i]));
                }
            }
        }
        return count(visited.begin(), visited.end(), true) == visited.size()
                   ? res
                   : -1;
    }
};

// Bellman Ford 算法 答案来自LeetCode  这种解法必须会 已经碰见好多次了
// 比较简单的Bellman Ford解法
// https://leetcode.com/problems/network-delay-time/discuss/109982/C++-Bellman-Ford
// 比较复杂的Bellman Ford解法 只做稍微的参考
// https://leetcode.com/problems/network-delay-time/discuss/109967/Simple-Java-Solution-using-BFS-(similar-to-dijkstra's-shortest-path-algorithm)-with-explanation
// 这里的解法是简单版
class Solution_0 {
  public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < times.size(); j++) {
                int u = times[j][0], v = times[j][1], w = times[j][2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};

// 非常标准的Dijkstra算法 来自LeetCode
// https://leetcode.com/problems/network-delay-time/discuss/109983/Straightforward-Python-Dijkstra's