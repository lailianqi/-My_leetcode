#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 这两个的链接不一样
// https://blog.csdn.net/pzx1997/article/details/71642958
// https://blog.csdn.net/u014182411/article/details/69831492

class Solution {
  public:
    TreeNode *insertNode(TreeNode *root, TreeNode *node) {
        // write your code here
        if (root == NULL)
            root = node;
        else {
            if (node->val < root->val)
                root->left = insertNode(root->left, node);
            else
                root->right = insertNode(root->right, node);
        }
        return root;
    }
};
