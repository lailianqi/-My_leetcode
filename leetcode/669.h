#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自己的第一种方案 成功ac
// LeetCode答案和自己的思想是一模一样的
// https://leetcode.com/problems/trim-a-binary-search-tree/discuss/107000/Java-solution-6-liner
// https://leetcode.com/problems/trim-a-binary-search-tree/discuss/107046/C++-recursion
class Solution {
  public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root) {
            if (root->val >= L && root->val <= R) {
                root->left = trimBST(root->left, L, root->val);
                root->right = trimBST(root->right, root->val, R);
                return root;
            }
            if (root->val < L) {
                return trimBST(root->right, L, R);
            } else {
                return trimBST(root->left, L, R);
            }
        }
        return NULL;
    }
};