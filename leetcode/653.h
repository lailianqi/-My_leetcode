#include <string>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 自己的第一种方案 成功ac
// LeetCode上面有类似思想的答案
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106059/JavaC++-Three-simple-methods-choose-one-you-like
class Solution {
  public:
    bool findTarget(TreeNode *root, int k) {
        if (root) {
            if (dir.count(k - root->val)) {
                return true;
            }
            dir.insert(root->val);
            return findTarget(root->left, k) || findTarget(root->right, k);
        }
        return false;
    }

  private:
    unordered_set<int> dir;
};

// 另外一种 就是树的迭代器 这里就不写出来了
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106063/C++-Clean-Code-O(n)-time-O(lg-n)-space-BinaryTree-Iterator