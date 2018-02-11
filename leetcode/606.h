#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方案 成功ac
class Solution {
  public:
    string tree2str(TreeNode *t) {
        string res;
        helper(t, res);
        return res;
    }
    void helper(TreeNode *root, string &str) {
        if (root) {
            str += to_string(root->val);
            if (root->left) {
                str += "(";
                helper(root->left, str);
                str += ")";
            }
            if (root->right) {
                if (root->left == NULL) {
                    str += "()";
                }
                str += "(";
                helper(root->right, str);
                str += ")";
            }
        }
    }
};

// leetcode 上面更加优秀的写法 当然思想和上面差不多
// https://discuss.leetcode.com/topic/91307/java-c-1-liner
class Solution_0 {
  public:
    string tree2str(TreeNode *t) {
        return t == NULL ? ""
                         : to_string(t->val) +
                               (t->left ? "(" + tree2str(t->left) + ")"
                                        : t->right != NULL ? "()" : "") +
                               (t->right ? "(" + tree2str(t->right) + ")" : "");
    }
};