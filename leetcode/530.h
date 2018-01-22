#include <algorithm>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方案 成功ac 这题比较简单
// LeetCode上和我的方案差不多的答案
// https://discuss.leetcode.com/topic/80823/two-solutions-in-order-traversal-and-a-more-general-way-using-treeset
class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        int res = INT_MAX, pre = -1;
        helper(root, pre, res);
        return res;
    }
    void helper(TreeNode *root, int &pre, int &res) {
        if (root) {
            helper(root->left, pre, res);
            if (pre != -1) {
                res = min(res, root->val - pre);
            }
            pre = root->val;
            helper(root->right, pre, res);
        }
    }
};