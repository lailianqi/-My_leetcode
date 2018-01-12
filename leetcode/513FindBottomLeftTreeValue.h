#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的第一种解法 成功ac
class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) {
        int maxDeep = getDeep(root);
        return helper(root, 1, maxDeep);
    }
    int helper(TreeNode *root, int deep, int maxDeep) {
        if (root) {
            if (deep == maxDeep) {
                return root->val;
            }
            int leftNum = helper(root->left, deep + 1, maxDeep);
            if (leftNum != -1) {
                return leftNum;
            }
            int rightNum = helper(root->right, deep + 1, maxDeep);
            if (rightNum != -1) {
                return rightNum;
            }
        }
        return -1;
    }
    int getDeep(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(getDeep(root->left), getDeep(root->right));
    }
};

// leetcode的解法 来自sp大神 代码量大大减少
// https://discuss.leetcode.com/topic/78981/right-to-left-bfs-python-java
class Solution_0 {
  public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            root = nodeQueue.front();
            nodeQueue.pop();
            if (root->right) {
                nodeQueue.push(root->right);
            }
            if (root->left) {
                nodeQueue.push(root->left);
            }
        }
        return root->val;
    }
};