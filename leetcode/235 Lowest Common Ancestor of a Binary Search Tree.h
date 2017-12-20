#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的方法
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q)
            return root;
        if ((root->val - p->val) * (root->val - q->val) < 0) {
            return root;
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};

// leetcode的解法
// https://discuss.leetcode.com/topic/18387/3-lines-with-o-1-space-1-liners-alternatives
class Solution_0 {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while ((root->val - p->val) * (root->val - q->val) > 0)
            root = p->val < root->val ? root->left : root->right;
        return root;
    }
};

// leetcode的解法 递归的解法
// https://discuss.leetcode.com/topic/18387/3-lines-with-o-1-space-1-liners-alternatives
class Solution_1 {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return (root->val - p->val) * (root->val - q->val) <= 0
                   ? root
                   : lowestCommonAncestor(
                         p->val < root->val ? root->left : root->right, p, q);
    }
};