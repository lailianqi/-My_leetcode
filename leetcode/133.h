#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

//自己的想法加上答案的想法，最初的自己的想法忘记用map记录点了
class Solution {
  public:
    map<int, UndirectedGraphNode *> directory;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        return clone(node);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        if (directory.find(node->label) != directory.end()) {
            return directory[node->label];
        }
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        directory[root->label] = root;
        for (int i = 0; i < node->neighbors.size(); i++) {
            root->neighbors.push_back(clone(node->neighbors[i]));
        }
        return root;
    }
};

// BFS
// https://discuss.leetcode.com/topic/4690/simple-java-iterative-bfs-solution-with-hashmap-and-queue
// Leetcode的解法，改为了c++
class Solution_0 {
  public:
    map<int, UndirectedGraphNode *> directory;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        queue<UndirectedGraphNode *> nodeQueue;
        map<int, UndirectedGraphNode *> directory;
        nodeQueue.push(node);
        directory[node->label] = new UndirectedGraphNode(node->label);
        while (!nodeQueue.empty()) {
            UndirectedGraphNode *nodeTemp = nodeQueue.front();
            nodeQueue.pop();
            for (auto neighbor : nodeTemp->neighbors) {
                if (directory.find(neighbor->label) == directory.end()) {
                    directory[neighbor->label] =
                        new UndirectedGraphNode(neighbor->label);
                    nodeQueue.push(neighbor);
                }
                directory[nodeTemp->label]->neighbors.push_back(
                    directory[neighbor->label]);
            }
        }
        return directory[node->label];
    }
};

// 二刷------------------------
class Solution {
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        return clone(node);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        if (dir.count(node->label)) {
            return dir[node->label];
        }
        dir[node->label] = new UndirectedGraphNode(node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            dir[node->label]->neighbors.push_back(clone(node->neighbors[i]));
        }
        return dir[node->label];
    }

  private:
    unordered_map<int, UndirectedGraphNode *> dir;
};