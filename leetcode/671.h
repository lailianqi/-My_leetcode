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

// 自己的第一种解法 成功ac
// LeetCode的解法其实思想和这个解法差不多
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/discuss/107159/C++-DFS-recursion
class Solution {
  public:
    int findSecondMinimumValue(TreeNode *root) {
        rootValue = root->val;
        helper(root);
        return res == INT_MAX ? -1 : res;
    }
    void helper(TreeNode *root) {
        if (root) {
            if (root->val < res && root->val != rootValue) {
                res = root->val;
            }
            helper(root->left);
            helper(root->right);
        }
    }

  private:
    int res = INT_MAX;
    int rootValue = 0;
};

//上面的稍微的改进版
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/discuss/107159/C++-DFS-recursion
class Solution_0 {
  public:
    int findSecondMinimumValue(TreeNode *root) {
        rootValue = root->val;
        return helper(root);
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return -1;
        }
        if (root->val != rootValue) {
            return root->val;
        }
        int left = helper(root->left), right = helper(root->right);
        return left == -1 ? right : right == -1 ? left : min(left, right);
    }

  private:
    int rootValue = 0;
};