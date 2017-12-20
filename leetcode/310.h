#include <vector>
#include <queue>
#include <set>
using namespace std;
//这题第一次没有写出来，但是应该要自己写出来的，因为207的拓扑排序题与这个类似
//下面的答案是基于207答案的改写，相比于leetcode的答案比较美观
//下面是 leetcode的答案
// https://discuss.leetcode.com/topic/30572/share-some-thoughts/2
// Your runtime beats 85.93 % of cpp submissions.
class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        if (n == 1) {
            return vector<int>(1, 0);
        }
        queue<int> nodeQueue;
        vector<set<int>> graphPaths = createGraph(edges, n);
        //  vector<int> degrees = compute_indegree(graphPaths);
        for (int i = 0; i < n; i++) { //把度数为1的点加入队列
            if (graphPaths[i].size() == 1) {
                nodeQueue.push(i);
            }
        }
        while (n > 2) {
            n = n - nodeQueue.size();
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                int edge = nodeQueue.front();
                nodeQueue.pop();
                for (auto element : graphPaths[edge]) {
                    graphPaths[element].erase(edge);
                    if (graphPaths[element].size() == 1) {
                        nodeQueue.push(element);
                    }
                }
            }
        }
        vector<int> result;
        while (!nodeQueue.empty()) {
            result.push_back(nodeQueue.front());
            nodeQueue.pop();
        }
        return result;
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
};