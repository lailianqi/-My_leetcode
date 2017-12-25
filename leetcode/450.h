#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//关于删除二叉树 有点忘记怎么删了 所以直接看的答案
// leetcode的答案
// https://discuss.leetcode.com/topic/65792/recursive-easy-to-understand-java-solution
class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) { return helper(root, key); }
    TreeNode *helper(TreeNode *root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            } else {
                TreeNode *minNode = root->right;
                while (minNode->left) {
                    minNode = minNode->left;
                }
                root->val = minNode->val;
                root->right = helper(root->right, root->val);
            }
        } else if (root->val > key) {
            root->left = helper(root->left, key);
        } else {
            root->right = helper(root->right, key);
        }
        return root;
    }
};

//上面算法的改进版  代码更加的简练
// https://discuss.leetcode.com/topic/65792/recursive-easy-to-understand-java-solution/10?page=1
// https://discuss.leetcode.com/topic/66165/very-concise-c-solution-for-general-binary-tree-not-only-bst/11
class Solution_0 {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            } else {
                TreeNode *rightSmallest = root->right;
                while (rightSmallest->left != NULL)
                    rightSmallest = rightSmallest->left;
                swap(root->val, rightSmallest->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};