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
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        return abs(TreeHeight(root->left) - TreeHeight(root->right)) <= 1 &&
               (isBalanced(root->left) && isBalanced(root->right));
    }
    int TreeHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    }
};

// 更加优化方案的解法
// https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better