#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//这种解法存在超时的错误
class Solution {
  public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2
class Solution_0 {
  public:
    int height(TreeNode *root) {
        return root == NULL ? -1 : 1 + height(root->left);
    }
    int countNodes(TreeNode *root) {
        int h = height(root);
        return h < 0 ? 0
                     : height(root->right) == h - 1
                           ? (1 << h) + countNodes(root->right)
                           : (1 << h - 1) + countNodes(root->left);
    }
};
//上面的方法的迭代版本  runtime beats 97.39 % of cpp submissions.
// https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2/2?page=1
class Solution_1 {
  public:
    int height(TreeNode *root) {
        return root == NULL ? -1 : 1 + height(root->left);
    }
    int countNodes(TreeNode *root) {
        int h = height(root), res = 0;
        TreeNode *curr = root;
        while (curr) {
            if (height(curr->right) == h - 1) {
                res += 1 << h;
                curr = curr->right;
            } else {
                res += 1 << (h - 1);
                curr = curr->left;
            }
            h--;
        }
        return res;
    }
};
//另外的一种递归
// https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2/2?page=1
class Solution_2 {
  public:
    int countNodes(TreeNode *root) {
        if (root == NULL)
            return 0;
        int height = 0;
        TreeNode *left = root, *right = root;
        while (right != NULL) {
            left = left->left;
            right = right->right;
            height++;
        }
        if (left == NULL)
            return (1 << height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};