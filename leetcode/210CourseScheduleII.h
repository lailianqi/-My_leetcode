#include <vector>
#include <set>
#include <queue>
using namespace std;
//自己参照问题 Course Schedule I写的，也就是207.h，顺利通过
//下面是leetcode的相似答案的链接
// https://discuss.leetcode.com/topic/17276/20-lines-c-bfs-dfs-solutions
class Solution {
  public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>> &prerequisites) {
        int counter = 0;
        vector<int> res;
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
            res.push_back(course);
            nodeQueue.pop();
            counter++;
            for (auto element : graphPaths[course]) {
                if (--degrees[element] == 0) {
                    nodeQueue.push(element);
                }
            }
        }
        return counter == numCourses ? res : vector<int>();
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