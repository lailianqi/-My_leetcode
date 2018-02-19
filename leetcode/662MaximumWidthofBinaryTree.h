#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 这题确实没写出来 直接看的答案 堆的索引的用法
// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106654/JavaC++-Very-simple-dfs-solution?page=1
// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106645/C++Java-*-BFSDFS3liner-Clean-Code-With-Explanation
class Solution {
  public:
    int widthOfBinaryTree(TreeNode *root) {
        return helper(root, 0, 1, vector<pair<int, int>>() = {});
    }

    int helper(TreeNode *root, int level, int order,
               vector<pair<int, int>> &vec) {
        if (root == NULL)
            return 0;
        if (vec.size() == level)
            vec.push_back({order, order});
        else
            vec[level].second = order;
        return max({vec[level].second - vec[level].first + 1,
                    helper(root->left, level + 1, 2 * order, vec),
                    helper(root->right, level + 1, 2 * order + 1, vec)});
    }
};