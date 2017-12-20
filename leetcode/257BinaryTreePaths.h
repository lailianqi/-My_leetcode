#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Your runtime beats 81.03 % of cpp submissions.
//自己的初始的解法 和 下面的leetcode的方法基本上一模一样
// https://discuss.leetcode.com/topic/21447/c-simple-4ms-recursive-solution
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (root)
            binaryTreePaths(root, res, to_string(root->val));
        return res;
    }
    void binaryTreePaths(TreeNode *root, vector<string> &res, string s) {
        if (root && root->left == NULL && root->right == NULL) {
            res.push_back(s);
            return;
        }
        if (root->left)
            binaryTreePaths(root->left, res,
                            s + "->" + to_string(root->left->val));
        if (root->right)
            binaryTreePaths(root->right, res,
                            s + "->" + to_string(root->right->val));
    }
};

// leetcode类似上面的解法
// https://discuss.leetcode.com/topic/21474/accepted-java-simple-solution-in-8-lines
// https://discuss.leetcode.com/topic/23047/clean-java-solution-accepted-without-any-helper-recursive-function/11
class Solution_0 {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (root)
            binaryTreePaths(root, res, "");
        return res;
    }
    void binaryTreePaths(TreeNode *root, vector<string> &res, string s) {
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s + to_string(root->val));
            return;
        }
        if (root->left)
            binaryTreePaths(root->left, res, s + to_string(root->val) + "->");
        if (root->right)
            binaryTreePaths(root->right, res, s + to_string(root->val) + "->");
    }
};
// python的解法
// https://discuss.leetcode.com/topic/21441/5-lines-recursive-python/2