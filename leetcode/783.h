#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 71周 比赛中完美ac
class Solution {
  public:
    int minDiffInBST(TreeNode *root) {
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