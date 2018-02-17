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
// 直接看的答案 因为题目的意思刚开始并没有理解完全
// https://leetcode.com/problems/print-binary-tree/discuss/106239/Java-Recursive-Solution
// https://leetcode.com/problems/print-binary-tree/discuss/113987/C++-Simple-solution-with-DFS-(pre-order-traversal)
class Solution {
  public:
    vector<vector<string>> printTree(TreeNode *root) {
        int h = height(root);
        int c = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(c));
        helper(root, 0, c - 1, 0, res);
        return res;
    }

  private:
    int height(TreeNode *root) {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void helper(TreeNode *root, int left, int right, int height,
                vector<vector<string>> &res) {
        if (root == NULL || left > right) {
            return;
        }
        int mid = (left + right) / 2;
        res[height][mid] = to_string(root->val);
        helper(root->left, left, mid - 1, height + 1, res);
        helper(root->right, mid + 1, right, height + 1, res);
    }
};