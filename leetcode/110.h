#include <string>
#include <cmath>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        return abs(TreeHeight(root->left) - TreeHeight(root->right)) <= 1 &&
               (isBalanced(root->left) && isBalanced(root->right));
    }
    int TreeHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    }
};