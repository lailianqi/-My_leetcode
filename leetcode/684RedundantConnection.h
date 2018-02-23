#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这种题目不是很熟 所以没写出来 直接看的答案 这题是关于union find 非常好的题目
// https://leetcode.com/problems/redundant-connection/discuss/107984/10-line-Java-solution-Union-Find.
// http://blog.csdn.net/Ulricalin/article/details/78162991
class Solution {
  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> parent(2001, 0);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (auto &element : edges) {
            if (findParent(parent, element[0]) ==
                findParent(parent, element[1])) {
                return element;
            } else {
                parent[findParent(parent, element[1])] =
                    findParent(parent, element[0]);
            }
        }
        return {0, 0};
    }
    // 第一种写法
    // int findParent(vector<int> &parent, int target) {
    //     while (parent[target] != target) {
    //         target = parent[target];
    //     }
    //     return target;
    // }
    // 第二种写法
    int findParent(vector<int> &parent, int target) {
        if (parent[target] != target) {
            parent[target] = findParent(parent, parent[target]);
        }
        return parent[target];
    }
};


// 官方的题解
// https://leetcode.com/problems/redundant-connection/solution/