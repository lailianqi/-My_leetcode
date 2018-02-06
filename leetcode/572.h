#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方案 成功ac
// leetcode上面类似的答案  思想一模一样 写法略有不同
// https://discuss.leetcode.com/topic/88508/java-solution-tree-traversal
class Solution {
  public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (isSameTree(s, t)) {
            return true;
        }
        if (s != NULL && ((isSubtree(s->left, t)) || isSubtree(s->right, t))) {
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode *t1, TreeNode *t2) {
        if (t1 != NULL && t2 != NULL && t1->val == t2->val) {
            return isSameTree(t1->left, t2->left) &&
                   isSameTree(t1->right, t2->right);
        }
        return t1 == NULL && t2 == NULL;
    }
};