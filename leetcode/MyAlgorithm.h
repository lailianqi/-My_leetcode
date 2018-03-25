#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isInVaildBoardary(vector<vector<int>> &grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row >= 0 && row < m && col >= 0 && col < n) {
        return true;
    }
    return false;
}

struct Comparator {
    bool operator()(const std::pair<int, int> &lhs,
                    const std::pair<int, int> &rhs) const {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        else
            return lhs.first < rhs.first;
    }
};

class Employee {
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
int helper(unordered_map<int, Employee *> &dir, int id) {
    return dir[id]->importance +
           accumulate(dir[id]->subordinates.begin(),
                      dir[id]->subordinates.end(), 0,
                      [&](int sum, int id) { return sum + helper(dir, id); });
}

int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, Employee *> dir;
    transform(
        employees.begin(), employees.end(), inserter(dir, dir.end()),
        [&](Employee *element) { return make_pair(element->id, element); });
    return helper(dir, id);
}

int minimumDeleteSum(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = A[i - 1] == B[j - 1] ? (dp[i - 1][j - 1] + 1)
                                            : (max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[m][n];
}

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size(); j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }
    return i == s.size();
}

int findParent(vector<int> &parent, int target) {
    if (parent[target] != target) {
        parent[target] = findParent(parent, parent[target]);
    }
    return parent[target];
}

vector<set<int>> createGraph(vector<pair<int, int>> &prerequisites,
                             int numCourses) {
    vector<set<int>> graphPaths(numCourses);
    for (auto element : prerequisites) {
        graphPaths[element.first].insert(element.second);
        graphPaths[element.second].insert(element.first);
    }
    return graphPaths;
}

int Dijkstra(vector<vector<int>> &graph, int source, int target,
             int N) { // 1.......N
    // auto graph = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
    vector<bool> visited(N + 1, false);
    visited[0] = true, visited[source] = true;
    auto comp = [](pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
        minStack(comp);
    for (int i = 0; i <= N; i++) {
        if (graph[source][i] >= 0) {
            minStack.push({i, graph[source][i]});
        }
    }
    while (!minStack.empty()) {
        auto current = minStack.top();
        minStack.pop();
        int target = current.first;
        if (visited[target]) {
            continue;
        }
        if (current.first == target) {
            return current.second;
        }
        visited[target] = true;
        for (int i = 0; i <= N; i++) {
            if (!visited[i] && graph[target][i] >= 0) {
                minStack.push(make_pair(i, current.second + graph[target][i]));
            }
        }
    }
    return -1;
}

int Bellman_Ford(vector<vector<int>> &times, int N, int source, int target) {
    vector<int> dist(N + 1, INT_MAX);
    dist[source] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < times.size(); j++) {
            int u = times[j][0], v = times[j][1], w = times[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist[target] == INT_MAX ? -1 : dist[target];
}

// 双向BFS Bidirectional BFS
// 752题