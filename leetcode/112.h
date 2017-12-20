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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        return backTrace(root, sum);
    }
    bool backTrace(TreeNode *root, int sum) {
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val)
                return true;
            return false;
        }
        if (root->left == NULL) {
            return backTrace(root->right, sum - root->val);
        }
        if (root->right == NULL) {
            return backTrace(root->left, sum - root->val);
        }
        return backTrace(root->left, sum - root->val) ||
               backTrace(root->right, sum - root->val);
    }
};

// LeetCode的答案
class Solution_0 {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};