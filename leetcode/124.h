#include <string>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int result = INT_MIN;
    int maxPathSum(TreeNode *root) {
        helper(root);
        return result;
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftPathSum = helper(root->left);
        int rightPathSum = helper(root->right);
        int currsum = max(
            max(leftPathSum + root->val, rightPathSum + root->val), root->val);
        int currMax = max(currsum, leftPathSum + rightPathSum + root->val);
        result = max(result, currMax);
        return currsum;
    }
};

class Solution_0 {
  public:
    int result = INT_MIN;
    int maxPathSum(TreeNode *root) {
        helper(root);
        return result;
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftPathSum = max(0, helper(root->left));
        int rightPathSum = max(0, helper(root->right));
        int currSum = root->val + leftPathSum + rightPathSum;
        result = max(result, currSum);
        return max(leftPathSum, rightPathSum) + root->val;
    }
};