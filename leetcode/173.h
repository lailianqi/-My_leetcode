#include <string>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// https://discuss.leetcode.com/topic/6604/ideal-solution-using-stack-java/20
// https://discuss.leetcode.com/topic/6575/my-solutions-in-3-languages-with-stack
// leetcode的答案,改写成 C++写法
class BSTIterator {
  public:
    stack<TreeNode *> nodeStack;
    BSTIterator(TreeNode *root) { inorderTraversal(root); }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !nodeStack.empty(); }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = nodeStack.top();
        nodeStack.pop();
        inorderTraversal(p->right);
        return p->val;
    }
    void inorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        while (p) {
            nodeStack.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */