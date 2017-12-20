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
    int kthSmallest(TreeNode *root, int k) {
        int leftNum = countNode(root->left);
        if (k == leftNum + 1) {
            return root->val;
        } else if (k > leftNum + 1) {
            return kthSmallest(root->right, k - leftNum - 1);
        } else {
            return kthSmallest(root->left, k);
        }
    }
    int countNode(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + countNode(root->left) + countNode(root->right);
    }
};

class Solution_0 {
  public:
    int kthSmallest(TreeNode *root, int k) {
        int number = 0;
        helper(root, k, number);
        return number;
    }
    void helper(TreeNode *root, int &counter, int &number) {
        if (root->left != NULL) {
            helper(root->left, counter, number);
        }
        counter--;
        if (counter == 0) {
            number = root->val;
            return;
        }
        if (root->right != NULL) {
            helper(root->right, counter, number);
        }
    }
};