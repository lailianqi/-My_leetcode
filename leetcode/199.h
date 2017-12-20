#include <vector>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的解法，拿一个队列遍历
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int m = nodeQueue.size();
            for (int i = 0; i < m; i++) {
                TreeNode *p = nodeQueue.front();
                if (p->left != NULL) {
                    nodeQueue.push(p->left);
                }
                if (p->right != NULL) {
                    nodeQueue.push(p->right);
                }
                if (i == m - 1) {
                    res.push_back(p->val);
                }
                nodeQueue.pop();
            }
        }
        return res;
    }
};

// leetCode的解法
//这个解法有一定的技巧，有趣
// https://discuss.leetcode.com/topic/11310/my-c-solution-modified-preorder-traversal
class Solution_0 {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode *root, int level, vector<int> &res) {
        if (root == NULL)
            return;
        if (res.size() == level)
            res.push_back(root->val);
        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }
};