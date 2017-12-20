#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的答案
class Solution {
  public:
    int result = 0;
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        sumNumbers(root, 0);
        return result;
    }
    void sumNumbers(TreeNode *root, int sum) {
        int currSum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            result += currSum;
        if (root->left != NULL)
            sumNumbers(root->left, currSum);
        if (root->right != NULL)
            sumNumbers(root->right, currSum);
    }
};

//自己的答案的简写版
class Solution_0 {
  public:
    int sumNumbers(TreeNode *root) { return sumNumbers(root, 0); }
    int sumNumbers(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return sum * 10 + root->val;
        }
        return sumNumbers(root->left, sum * 10 + root->val) +
               sumNumbers(root->right, sum * 10 + root->val);
    }
};