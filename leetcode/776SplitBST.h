#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// LeetCode第70周周赛
// 比赛中没有写出
// 记住 只要输出分离后两颗树的根就行 output有误导的作用
// 下面是LeetCode的答案
// https://discuss.leetcode.com/topic/119462/my-3-lines-c-recursive-solution
// https://discuss.leetcode.com/topic/119488/yet-another-short-recursive-c-solution-4ms
class Solution {
  public:
    vector<TreeNode *> splitBST(TreeNode *root, int V) {
        vector<TreeNode *> res(2, NULL);
        if (root == NULL) {
            return res;
        }
        if (root->val > V) {
            res[1] = root;
            auto leftRes = splitBST(root->left, V);
            root->left = leftRes[1];
            res[0] = leftRes[0];
        } else {
            res[0] = root;
            auto rightRes = splitBST(root->right, V);
            root->right = rightRes[0];
            res[1] = rightRes[1];
        }
        return res;
    }
};

// 比上面更加简洁的写法 来自LeetCode
// https://discuss.leetcode.com/topic/119488/yet-another-short-recursive-c-solution-4ms
class Solution_0 {
  public:
    vector<TreeNode *> splitBST(TreeNode *root, int V) {
        if (root == NULL) {
            return {NULL, NULL};
        }
        if (root->val > V) {
            auto leftRes = splitBST(root->left, V);
            root->left = leftRes[1];
            return {leftRes[0], root};
        } else {
            auto rightRes = splitBST(root->right, V);
            root->right = rightRes[0];
            return {root, rightRes[1]};
        }
    }
};