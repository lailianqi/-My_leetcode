#include <unordered_set>
#include <vector>
using namespace std;
// 最简单的做法
// 采用建立递归树的解法求解 成功ac
// LeetCode上面类似的答案
// https://discuss.leetcode.com/topic/85031/neat-dfs-java-solution
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &M) {
        int m = M.size(), res = 0;
        vector<bool> visited(m, false);
        for (int i = 0; i < M.size(); i++) {
            if (!visited[i]) {
                res++;
                helper(M, i, visited);
            }
        }
        return res;
    }
    void helper(vector<vector<int>> &M, int i, vector<bool> &visited) {
        for (int j = 0; j < M[i].size(); j++) {
            if (M[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                helper(M, j, visited);
            }
        }
    }
};
// python的解法 根本看不懂 来自LeetCode的sp大神的解法
// https://discuss.leetcode.com/topic/85108/oneliners-p

// 还有一种解法 Union Find 但是代码太长 但是写的不错
// https://discuss.leetcode.com/topic/85039/java-solution-union-find
// https://discuss.leetcode.com/topic/85039/java-solution-union-find/4
// https://discuss.leetcode.com/topic/85039/java-solution-union-find/5
class Solution_0 {
  public:
    int findCircleNum(vector<vector<int>> &M) {
        int m = M.size(), res = 0;
        vector<int> root(m, 0);
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
                if (M[i][j] == 1)
                    unionFind(root, i, j);
        for (int i = 0; i < m; i++)
            if (i == root[i])
                res++;
        return res;
    }
    void unionFind(vector<int> &root, int v1, int v2) {
        while (root[v1] != v1)
            v1 = root[v1]; // find v1's root
        while (root[v2] != v2)
            v2 = root[v2]; // find v2's root
        if (root[v1] != root[v2])
            root[v2] = v1; // unite the 2 subtrees
    }
};
void test() {
    Solution s;
    vector<vector<int>> M = {
        {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    s.findCircleNum(M);
}