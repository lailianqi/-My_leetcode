#include <climits>
#include <string>
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

// ------------------------------ 二刷
class Solution_1 {
  private:
    int res = INT_MIN;

  public:
    int maxPathSum(TreeNode *root) {
        helper(root);
        return res;
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left_num = max(0, helper(root->left)),
            right_num = max(0, helper(root->right));
        int curr = left_num + right_num + root->val;
        res = max(res, curr);
        return max(left_num, right_num) + root->val;
    }
};