#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
// leetcode的答案,拓扑排序的写法，有点忘了，所以这题没有写出来
// https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions?page=1
class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<set<int>> graphPaths = createGraph(prerequisites, numCourses);
        vector<int> degrees = compute_indegree(graphPaths);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (j = 0; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j] = -1;
            for (auto element : graphPaths[j]) {
                degrees[element]--;
            }
        }
        return true;
    }
    vector<set<int>> createGraph(vector<pair<int, int>> &prerequisites,
                                 int numCourses) {
        vector<set<int>> graphPaths(numCourses);
        for (auto element : prerequisites) {
            graphPaths[element.second].insert(element.first);
        }
        return graphPaths;
    }
    vector<int> compute_indegree(vector<set<int>> &graphPaths) {
        vector<int> degrees(graphPaths.size(), 0);
        for (auto neighbors : graphPaths) {
            for (auto neighbor : neighbors) {
                degrees[neighbor]++;
            }
        }
        return degrees;
    }
};
//另外一种写法，直接用队列,效率非常的高
// https://discuss.leetcode.com/topic/13854/easy-bfs-topological-sort-java
// https://discuss.leetcode.com/topic/13854/easy-bfs-topological-sort-java/24?page=2

class Solution_0 {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        int counter = 0;
        queue<int> nodeQueue;
        vector<set<int>> graphPaths = createGraph(prerequisites, numCourses);
        vector<int> degrees = compute_indegree(graphPaths);
        for (int i = 0; i < degrees.size(); i++) { //把度数为0的点加入队列
            if (!degrees[i]) {
                nodeQueue.push(i);
            }
        }
        while (!nodeQueue.empty()) {
            int course = nodeQueue.front();
            nodeQueue.pop();
            counter++;
            for (auto element : graphPaths[course]) {
                if (--degrees[element] == 0) {
                    nodeQueue.push(element);
                }
            }
        }
        return counter == numCourses;
    }
    vector<set<int>> createGraph(vector<pair<int, int>> &prerequisites,
                                 int numCourses) {
        vector<set<int>> graphPaths(numCourses);
        for (auto element : prerequisites) {
            graphPaths[element.second].insert(element.first);
        }
        return graphPaths;
    }
    vector<int> compute_indegree(vector<set<int>> &graphPaths) {
        vector<int> degrees(graphPaths.size(), 0);
        for (auto neighbors : graphPaths) {
            for (auto neighbor : neighbors) {
                degrees[neighbor]++;
            }
        }
        return degrees;
    }
};
// DFS的写法
// https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions?page=1
class Solution_1 {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<set<int>> graphPaths = createGraph(prerequisites, numCourses);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && helper(i, graphPaths, onpath, visited)) {
                return false;
            }
        }
        return true;
    }
    vector<set<int>> createGraph(vector<pair<int, int>> &prerequisites,
                                 int numCourses) {
        vector<set<int>> graphPaths(numCourses);
        for (auto element : prerequisites) {
            graphPaths[element.second].insert(element.first);
        }
        return graphPaths;
    }
    bool helper(int node, vector<set<int>> &graphPaths, vector<bool> &onpath,
                vector<bool> &visited) {
        if (visited[node]) {
            return false;
        }
        onpath[node] = visited[node] = true;
        for (int neighbor : graphPaths[node]) {
            if (onpath[neighbor] ||
                helper(neighbor, graphPaths, onpath, visited)) {
                return true;
            }
        }
        onpath[node] = false;
        return false;
    }
};