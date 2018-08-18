#include <cmath>
#include <string>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//参考LeetCode题解
class Solution {
  public:
    TreeNode *pre = NULL;
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};

// 类似morris 但是这个并不是中序遍历
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
class Solution_0 {
  public:
    void flatten(TreeNode *root) {
        auto current = root;
        while (current) {
            auto pre = current->left;
            if (pre) {
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};