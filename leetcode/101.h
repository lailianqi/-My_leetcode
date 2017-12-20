#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己写的方案
class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root != NULL) {
            return isMirrorTree(root->left, root->right);
        }
        return true;
    }
    bool isMirrorTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL)
            return (p == q);
        return p->val == q->val && isMirrorTree(p->left, q->right) &&
               isMirrorTree(p->right, q->left);
    }
};

//下面是运用队列写的
// https://discuss.leetcode.com/topic/30155/easy-and-simple-using-one-queue-iterative-in-java

class Solution_0 {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode *> queueInstance;
        queueInstance.push(root->left);
        queueInstance.push(root->right);
        while (!queueInstance.empty()) {
            TreeNode *curNode1 = queueInstance.front();
            queueInstance.pop();
            TreeNode *curNode2 = queueInstance.front();
            queueInstance.pop();
            if (curNode1 == NULL && curNode2 == NULL)
                continue;
            if (curNode1 == NULL || curNode2 == NULL)
                return false;
            if (curNode1->val != curNode2->val)
                return false;
            queueInstance.push(curNode1->left);
            queueInstance.push(curNode2->right);
            queueInstance.push(curNode1->right);
            queueInstance.push(curNode2->left);
        }
        return true;
    }
};