#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的解法，但是效率不高，时间太长
// Your runtime beats 0.66 % of cpp submissions.
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (IsHasThisTreeNode(root->left, p) &&
            IsHasThisTreeNode(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (IsHasThisTreeNode(root->right, p) &&
            IsHasThisTreeNode(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    bool IsHasThisTreeNode(TreeNode *root, TreeNode *target) {
        if (root == NULL)
            return false;
        if (root == target)
            return true;
        return IsHasThisTreeNode(root->left, target) ||
               IsHasThisTreeNode(root->right, target);
    }
};
// leetcode的解法
//我上一种解法的终极进化版
// https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby
class Solution_0 {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left == NULL ? right : right == NULL ? left : root;
    }
};