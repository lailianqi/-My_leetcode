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
    bool operator()(const pair<int, int> &lhs,
                    const pair<int, int> &rhs) const {
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

vector<set<int>> createGraph(vector<pair<int, int>> &prerequisites,
                             int numCourses) {
    vector<set<int>> graphPaths(numCourses);
    for (auto element : prerequisites) {
        graphPaths[element.first].insert(element.second);
        graphPaths[element.second].insert(element.first);
    }
    return graphPaths;
}

struct comp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
};
// 邻接矩阵做的迪杰斯特拉算法
int Dijkstra(vector<vector<int>> &graph, int source, int target,
             int N) { // 1.......N
    // auto graph = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
    vector<bool> visited(N + 1, false);
    visited[0] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> minStack;
    minStack.push({source, 0});
    while (!minStack.empty()) {
        auto current = minStack.top();
        minStack.pop();
        int arrived = current.first;
        if (visited[arrived]) {
            continue;
        }
        if (arrived == target) {
            return current.second;
        }
        visited[arrived] = true;
        for (int i = 0; i <= N; i++) {
            if (!visited[i] && graph[arrived][i] >= 0) {
                minStack.push(make_pair(i, current.second + graph[arrived][i]));
            }
        }
    }
    return -1;
}

// 边来做的迪杰斯特拉算法
int Dijkstra2(unordered_map<int, vector<pair<int, int>>> &graph, int source,
              int target, int N) {
    vector<bool> visited(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> minStack;
    minStack.push({source, 0});
    while (!minStack.empty()) {
        auto current = minStack.top();
        minStack.pop();
        int arrived = current.first;
        if (visited[arrived]) {
            continue;
        }
        if (arrived == target) {
            return current.second;
        }
        visited[arrived] = true;
        for (int i = 0; i < graph[arrived].size(); i++) {
            if (!visited[graph[arrived][i].first]) {
                minStack.push(
                    make_pair(graph[arrived][i].first,
                              current.second + graph[arrived][i].second));
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

// 这种递归的和while的思想其实是一样的
// while在下面的union_find里面
int findParent(vector<int> &parent, int target) {
    if (parent[target] != target) {
        parent[target] = findParent(parent, parent[target]);
    }
    return parent[target];
}

// union find解法
/*
class UnionFind{
        int[] father;
        int[] count;
        UnionFind(int len) {
            father = new int[len];
            count = new int[len];
            for (int i = 0; i < len ; i++) {
                father[i] = i;
                count[i] = 1;
            }
        }
        


        int find(int toFind) {
            while(father[toFind] != toFind) {
                father[toFind] = father[father[toFind]];
                toFind = father[toFind];
            }
            return toFind;
        }

        void union(int a, int b) {
            int fatherA = find(a);
            int fatherB = find(b);
            if (fatherA != fatherB) {
                father[fatherA] = fatherB;
                count[fatherB] += count[fatherA];
            }
        }
    }
*/