#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    TreeNode *pre = NULL;
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;
    void recoverTree(TreeNode *root) {
        pre = new TreeNode(INT_MIN);
        traverse(root);
        swap(node1->val, node2->val);
    }
    void traverse(TreeNode *root) {
        if (root != NULL) {
            traverse(root->left);
            // Do some business
            if (node1 == NULL && pre->val >= root->val) {
                node1 = pre;
            }
            if (node1 != NULL && pre->val >= root->val) {
                node2 = root;
            }
            pre = root;
            traverse(root->right);
        }
    }
};