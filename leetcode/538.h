#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自己的第一种写法 成功ac
// 发现自己的解法与LeetCode上面一模一样
// https://discuss.leetcode.com/topic/83455/java-recursive-o-n-time
// https://discuss.leetcode.com/topic/83458/java-solution-7-liner-reversed-traversal
class Solution {
  public:
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    int helper(TreeNode *root, int &sum) {
        if (root) {
            root->val += helper(root->right, sum);
            sum = root->val;
            helper(root->left, sum);
        }
        return sum;
    }
};
// 自己的第二种写法 成功ac
// LeetCode上面也有类似的答案
// https://discuss.leetcode.com/topic/83455/java-recursive-o-n-time/3
class Solution_0 {
  public:
    TreeNode *convertBST(TreeNode *root) {
        helper(root, 0);
        return root;
    }
    int helper(TreeNode *root, int sum) {
        if (root) {
            root->val += helper(root->right, sum);
            int result = helper(root->left, root->val);
            return result;
        }
        return sum;
    }
};