#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的第一种方案 成功ac 使用了旧的节点
class Solution {
  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
        return t1 ? t1 : t2;
    }
};

// 不使用旧节点的方案
class Solution_0 {
  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        TreeNode *root = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        root->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        root->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return root;
    }
};
