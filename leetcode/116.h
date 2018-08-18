#include <queue>
#include <string>
#include <vector>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
//标准的递归的写法
class Solution {
  public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        if (root->left != NULL) {
            root->left->next = root->right;
            if (root->next != NULL) {
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
    }
};
//参照LeetCode的写法
class Solution_0 {
  public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *pre = root;
        TreeLinkNode *cur = NULL;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};

// ------------------二刷
class Solution_2 {
  public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right && root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};