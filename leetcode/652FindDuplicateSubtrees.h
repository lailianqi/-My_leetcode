#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这题没写出来 直接看的答案
// https://leetcode.com/problems/find-duplicate-subtrees/discuss/106011/Java-Concise-Postorder-Traversal-Solution
// https://leetcode.com/problems/find-duplicate-subtrees/discuss/106055/C++-Java-Clean-Code
class Solution {
  public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        helper(root);
        return res;
    }
    string helper(TreeNode *root) {
        if (root == NULL) {
            return "#";
        }
        string serial =
            to_string(root->val) + helper(root->left) + helper(root->right);
        if (dir[serial] == 1) {
            res.push_back(root);
        }
        dir[serial]++;
        return serial;
    }

  private:
    vector<TreeNode *> res;
    unordered_map<string, int> dir;
};