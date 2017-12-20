#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p != NULL && q != NULL) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) &&
                       isSameTree(p->right, q->right);
            }
        }
        if (p == NULL && q == NULL) {
            return true;
        }
        return false;
    }
};

class Solution_0 {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL)
            return (p == q);
        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};