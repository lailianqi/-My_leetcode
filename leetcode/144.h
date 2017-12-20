#include <stack>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己写的递归的写法，没有任何的价值
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
    void preorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL)
            return;
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
};
//自己写的非递归算法
//下面是类似的解法
// https://discuss.leetcode.com/topic/6493/accepted-iterative-solution-in-java-using-stack/3
class Solution_0 {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode *currentNode = nodeStack.top();
            nodeStack.pop();
            res.push_back(currentNode->val);
            if (currentNode->right != NULL) {
                nodeStack.push(currentNode->right);
            }
            if (currentNode->left != NULL) {
                nodeStack.push(currentNode->left);
            }
        }
        return res;
    }
};