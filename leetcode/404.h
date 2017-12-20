#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//马上就写出来了 挺简单的
class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        TreeNode *left = root->left;
        if (left && left->left == NULL && left->right == NULL) {
            return left->val + sumOfLeftLeaves(root->right);
        } else {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
};