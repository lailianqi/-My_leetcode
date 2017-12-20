#include <string>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归的写法
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        doInorderTraversal(root, answer);
        return answer;
    }
    void doInorderTraversal(TreeNode *root, vector<int> &answer) {
        if (root == NULL) {
            return;
        }
        doInorderTraversal(root->left, answer);
        answer.push_back(root->val);
        doInorderTraversal(root->right, answer);
    }
};
// Leetcode堆栈的写法
class Solution_0 {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        vector<TreeNode *> stack;
        TreeNode *curNode = root;
        while (curNode || !stack.empty()) {
            if (curNode) {
                stack.push_back(curNode);
                curNode = curNode->left;
            } else {
                curNode = stack.back();
                stack.pop_back();
                answer.push_back(curNode->val);
                curNode = curNode->right;
            }
        }
        return answer;
    }
};

//终极的写法
// https://discuss.leetcode.com/topic/46016/learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-java-solution