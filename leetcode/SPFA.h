#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// HDU 2680
void spfa(int distance, vector<vector<int>> &matrixs, vector<int> &dist) {
    int m = matrixs.size();
    vector<bool> visited(m, false);
    queue<int> nodeQueue;
    nodeQueue.push(distance);
    dist[distance] = 0;
    visited[distance] = true;
    while (!nodeQueue.empty()) {
        int node = nodeQueue.front();
        nodeQueue.pop();
        visited[node] = false;
        for (int i = 1; i < m; i++) {
            if (dist[node] != INT_MAX && matrixs[node][i] != INT_MAX &&
                (dist[i] > dist[node] + matrixs[node][i])) {
                dist[i] = dist[node] + matrixs[node][i];
                if (!visited[i]) {
                    visited[i] = true;
                    nodeQueue.push(i);
                }
            }
        }
    }
}
void test() {
    int n, m, s;
    int x, y, t;
    while (~scanf("%d%d%d", &n, &m, &s)) {
        int sum = INT_MAX;
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));
        vector<int> dist(n + 1, INT_MAX);
        for (int i = 0; i <= n; i++) {
            matrix[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &t);
            matrix[y][x] = min(t, matrix[y][x]);
        }
        spfa(s, matrix, dist);
        scanf("%d", &m);
        while (m--) {
            int num;
            scanf("%d", &num);
            sum = min(sum, dist[num]);
        }
        printf("%d\n", sum == INT_MAX ? -1 : sum);
    }
}

void test1() {
    int n, m, s;
    int x, y, t;
    while (~scanf("%d%d%d", &n, &m, &s)) {
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));
        vector<int> dist(n + 1, INT_MAX);
        for (int i = 0; i <= n; i++) {
            matrix[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &t);
            matrix[x][y] = min(t, matrix[x][y]);
        }
        scanf("%d", &m);
        while (m--) {
            int num;
            scanf("%d", &num);
            matrix[0][num] = 0;
        }
        spfa(0, matrix, dist);
        printf("%d\n", dist[s] == INT_MAX ? -1 : dist[s]);
    }
}

// 上面是spfa的测试

// 这里是Dijkstra
void dijst(int distance, vector<vector<int>> &matrixs, vector<int> &dist) {
    int m = matrixs.size();
    vector<bool> visited(m, false);
    dist[distance] = 0;
    visited[distance] = true;
    for (int i = 0; i < m; i++) {
        dist[i] = matrixs[distance][i];
    }
    for (int i = 0; i < m; ++i) {
        int temp = INT_MAX, k;
        for (int j = 0; j < m; j++) {
            if (!visited[j] && temp > dist[j]) {
                temp = dist[k = j];
            }
        }
        if (temp == INT_MAX)
            break;
        visited[k] = true;
        for (int j = 0; j < m; ++j) {
            if (!visited[j] && matrixs[k][j] != INT_MAX &&
                dist[j] > dist[k] + matrixs[k][j]) {
                dist[j] = dist[k] + matrixs[k][j];
            }
        }
    }
}
void test3() {
    int n, m, s;
    int x, y, t;
    while (~scanf("%d%d%d", &n, &m, &s)) {
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));
        vector<int> dist(n + 1, INT_MAX);
        for (int i = 0; i <= n; i++) {
            matrix[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &t);
            matrix[x][y] = min(t, matrix[x][y]);
        }
        scanf("%d", &m);
        while (m--) {
            int num;
            scanf("%d", &num);
            matrix[0][num] = 0;
        }
        dijst(0, matrix, dist);
        printf("%d\n", dist[s] == INT_MAX ? -1 : dist[s]);
    }
}
