#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的错误写法
class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return (root->left == NULL ? true : (root->left->val < root->val &&
                                             isValidBST(root->left))) &&
               (root->right == NULL ? true : (root->right->val > root->val &&
                                              isValidBST(root->right)));
    }
    bool do_isValidBST();
};

class Solution_0 {
  public:
    bool isValidBST(TreeNode *root) {
        vector<int> answer;
        doInorderTraversal(root, answer);
        for (int i = 1; i < answer.size(); i++) {
            if (answer[i] <= answer[i - 1])
                return false;
        }
        return true;
    }

    void doInorderTraversal(TreeNode *root, vector<int> &answer) {
        if (root == NULL) {
            return;
        }
        doInorderTraversal(root->left, answer);
        answer.push_back(root->val);
        doInorderTraversal(root->right, answer);
    }
};

class Solution_1 {
  public:
    TreeNode *pre = NULL;
    bool isValidBST(TreeNode *root) {
        if (root != NULL) {
            if (!isValidBST(root->left)) {
                return false;
            }
            if (pre != NULL && root->val <= pre->val) {
                return false;
            }
            pre = root;
            return isValidBST(root->right);
        }
        return true;
    }
};
//
/*
public class Solution {
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        if (root.left != null && root.val <= root.left.val) return false;
        if (root.right != null && root.val >= root.right.val) return false;
        return isValidBST(root.left) && isValidBST(root.right);
    }
}
*/

class Solution_2 {
public:
  bool isValidBST(TreeNode *root) { return isValidBST(root, NULL, NULL); }

  bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
      if (!root)
          return true;
      if ((minNode && root->val <= minNode->val) ||
          (maxNode && root->val >= maxNode->val))
          return false;
      return isValidBST(root->left, minNode, root) &&
             isValidBST(root->right, root, maxNode);
  }
};
