#include <string>
#include <vector>
#include <map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
3
/ \
2   3
\   \
 3   1
 Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 */
//自己的第一种方案，成功ac，但耗时非常的长
class Solution {
  public:
    int rob(TreeNode *root) { return helper(root, true); }
    int helper(TreeNode *root, bool flag) {
        if (root == NULL) {
            return 0;
        }
        if (flag == true) {
            return max(root->val + helper(root->left, false) +
                           helper(root->right, false),
                       helper(root->left, true) + helper(root->right, true));
        } else {
            return helper(root->left, true) + helper(root->right, true);
        }
    }
};
// 自己对上面方法的改写，对速度的提升微乎其微
//在leetcode发现相同的解法,下面是链接
// https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem
class Solution_0 {
  public:
    int rob(TreeNode *root) { return helper(root); }
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left || root->right) {
            return max(
                root->val +
                    (root->left == NULL ? 0 : helper(root->left->left) +
                                                  helper(root->left->right)) +
                    (root->right == NULL ? 0 : helper(root->right->left) +
                                                   helper(root->right->right)),
                helper(root->left) + helper(root->right));
        }
        return root->val;
    }
};
//备忘录的解法，速度提升超多 参考了leetcode的答案
// https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem
class Solution_1 {
  public:
    int rob(TreeNode *root) {
        map<TreeNode *, int> dictionary;
        return helper(root, dictionary);
    }
    int helper(TreeNode *root, map<TreeNode *, int> &dictionary) {
        int result = 0;
        if (root == NULL) {
            return result;
        }
        if (dictionary.find(root) != dictionary.end()) {
            return dictionary[root];
        }
        if (root->left || root->right) {
            result = max(root->val +
                             (root->left == NULL
                                  ? 0
                                  : helper(root->left->left, dictionary) +
                                        helper(root->left->right, dictionary)) +
                             (root->right == NULL
                                  ? 0
                                  : helper(root->right->left, dictionary) +
                                        helper(root->right->right, dictionary)),
                         helper(root->left, dictionary) +
                             helper(root->right, dictionary));
        }
        result = max(result, root->val);
        dictionary[root] = result;
        return result;
    }
};

//还有的一种思路 上面方法的延伸
// 我觉得最牛逼的解法
// https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem/2

class Solution_2 {
  public:
    int rob(TreeNode *root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode *root) {
        vector<int> res(2, 0);
        if (root == nullptr) {
            return res;
        }
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
};