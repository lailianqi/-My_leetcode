#include <algorithm>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方案 成功ac
// leetcode上面和这个一样一样的答案 相似度居然100%
// https://discuss.leetcode.com/topic/83456/java-solution-maxdepth
class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        helper(root);
        return maxLength == INT_MIN ? 0 : maxLength - 1;
    }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        maxLength = max(maxLength, 1 + left + right);
        return max(left, right) + 1;
    }

  private:
    int maxLength = INT_MIN;
};

// leetcode上面python的答案
// https://discuss.leetcode.com/topic/83481/python-simple-with-explanation
// https://discuss.leetcode.com/topic/83486/simple-python