
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
//递归初始版
class Solution {
  public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *cur = root;
        TreeLinkNode *pre = NULL;
        while (cur) {
            if (cur->left != NULL) {
                if (pre != NULL) {
                    pre->next = cur->left;
                }
                pre = cur->left;
            }
            if (cur->right != NULL) {
                if (pre != NULL) {
                    pre->next = cur->right;
                }
                pre = cur->right;
            }
            cur = cur->next;
        }
        connect(root->left);
        connect(root->right);
    }
};
//参照LeetCode的写法，使用额外点,并加以改进，使用了常量空间，也是最佳的方法
class Solution_0 {
  public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root;
        TreeLinkNode *pivot = new TreeLinkNode(0);
        while (cur) {
            TreeLinkNode *pre = pivot;
            while (cur) {
                if (cur->left != NULL) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right != NULL) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = pivot->next;
            pivot->next = NULL;
        }
    }
};
//第二中方法，递归d的写法
class Solution_1 {
  public:
    TreeLinkNode *pivot = new TreeLinkNode(0);
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        pivot->next = NULL;
        TreeLinkNode *cur = root;
        TreeLinkNode *pre = pivot;
        while (cur) {
            if (cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if (cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
            cur = cur->next;
        }
        connect(pivot->next);
    }
};

// ------------------二刷
class Solution_2 {
  public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        auto cur = root;
        TreeLinkNode *pivot = new TreeLinkNode(-1);
        while (cur) {
            TreeLinkNode *pre = pivot;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = pivot->next;
            pivot->next = NULL;
        }
    }
};