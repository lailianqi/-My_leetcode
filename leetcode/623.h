#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自己的第一种方案 成功ac 但是答案太长了
class Solution {
  public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        return helper(root, v, d);
    }
    TreeNode *helper(TreeNode *root, int v, int d) {
        if (root == NULL) {
            return NULL;
        }
        if (d == 1) {
            TreeNode *left = new TreeNode(v);
            left->left = root;
            root = left;
        } else if (d == 2) {
            TreeNode *left = new TreeNode(v);
            left->left = root->left;
            root->left = left;
            TreeNode *right = new TreeNode(v);
            right->right = root->right;
            root->right = right;
        } else {
            root->left = helper(root->left, v, d - 1);
            root->right = helper(root->right, v, d - 1);
        }
        return root;
    }
};

// 上面的改写 来自LeetCode的写法
// https://leetcode.com/problems/add-one-row-to-tree/discuss/104555/C++-Java-10-line-Solution-no-helper
class Solution_0 {
  public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d < 2) {
            TreeNode *newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root) {
            root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
};