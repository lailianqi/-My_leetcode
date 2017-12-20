#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *left = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = left;
        return root;
    }
};
//下面的代码格式更好看
// https://discuss.leetcode.com/topic/16138/recursive-and-non-recursive-c-both-4ms
class Solution_0 {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};
//未递归的版本
// https://discuss.leetcode.com/topic/16138/recursive-and-non-recursive-c-both-4ms
class Solution_1 {
  public:
    TreeNode *invertTree(TreeNode *root) {
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};