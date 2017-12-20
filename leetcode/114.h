#include <cmath>
#include <string>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//参考LeetCode题解
class Solution {
  public:
    TreeNode *pre = NULL;
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};