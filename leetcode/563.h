#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方法 成功ac 这道题比较简单
// LeetCode上面的答案和这个方法几乎是一模一样的
// https://discuss.leetcode.com/topic/87207/java-solution-post-order-traversal
class Solution {
  public:
    int findTilt(TreeNode *root) {
        helper(root);
        return res;
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        res += abs(left - right);
        return root->val + left + right;
    }

  private:
    int res = 0;
};