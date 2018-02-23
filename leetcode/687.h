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

// 这道题以前写过 成功ac 类似于543题
// leetcode上面和这个差不多的答案
// https://leetcode.com/problems/longest-univalue-path/discuss/108175/java-solution-with-global-variable
// https://leetcode.com/problems/longest-univalue-path/discuss/108142/Python-Simple-to-Understand
class Solution {
  public:
    int longestUnivaluePath(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        helper(root, root->val);
        return res;
    }
    int helper(TreeNode *root, int val) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left, root->val),
            right = helper(root->right, root->val);
        res = max(res, left + right);
        if (val == root->val) {
            return max(left, right) + 1;
        }
        return 0;
    }

  private:
    int res = 0;
};