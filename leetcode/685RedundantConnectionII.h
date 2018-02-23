#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 直接看的答案
/*
 * 1. 有2个parent节点，无环
 * 2. 只有环
 * 3. 有2个parent节点，有环
 *
 * 1.有个节点有两个父亲
 * 2.有环因此我们先遍历一次所有边，看看是否有节点有两个父亲，
 * 有的话记录下来，记这两条边为e1，e2，并且把后面出现的那条边e2删除，
 * 然后判断剩余边是否是一棵合法树，是则应删除e2，否则应删除e1。
 * 如果没有节点有两个父亲，就意味着有一个包括了根节点的环。
 * 一条一条边加入构图，看看是否成环，只需判断加入的边u，v是否有共同祖先。
 *
 */

// http://blog.csdn.net/u011934885/article/details/78705797
// http://blog.csdn.net/ulricalin/article/details/78244654
// https://leetcode.com/problems/redundant-connection-ii/discuss/108045/C++Java-Union-Find-with-explanation-O(n)
// https://leetcode.com/problems/redundant-connection-ii/discuss/108058/one-pass-disjoint-set-solution-with-explain

class Solution {
  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge : edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }

        // step 2, union find
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (auto &edge : edges) {
            if (edge[1] == 0)
                continue;
            int u = edge[0], v = edge[1], pu = findParent(parent, u);
            if (pu == edge[1]) {
                if (candA.empty())
                    return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }

    int findParent(vector<int> &parent, int target) {
        if (parent[target] != target) {
            parent[target] = findParent(parent, parent[target]);
        }
        return parent[target];
    }
};

// 第二种写法 其实和上面的思想一模一样
// https://leetcode.com/problems/redundant-connection-ii/discuss/108058/one-pass-disjoint-set-solution-with-explain

class Solution_0 {
  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int m = edges.size();
        vector<int> DParent(m + 1, 0), UParent(m + 1, 0);
        vector<int> first, second, three;
        for (int i = 1; i <= m; i++)
            UParent[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            int source = edges[i][0], destination = edges[i][1];
            if (DParent[destination] != 0) {
                first = {DParent[destination], destination};
                second = {source, destination};
                continue;
            }
            DParent[destination] = source;
            if (findParent(UParent, source) == destination) {
                three = {source, destination};
            } else {
                UParent[destination] = findParent(UParent, source);
            }
        }
        if (three.empty()) { // no cycle found by removing second
            return second;
        }
        if (second.empty()) { // no edge removed
            return three;
        }
        return first;
    }
    int findParent(vector<int> &parent, int target) {
        if (parent[target] != target) {
            parent[target] = findParent(parent, parent[target]);
        }
        return parent[target];
    }
};
