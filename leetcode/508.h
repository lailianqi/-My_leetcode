#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的第一种方法 成功ac 但是代码太长
// leetcode 上的答案和这个方法的思路一模一样 代码也很长
// https://discuss.leetcode.com/topic/77775/verbose-java-solution-postorder-traverse-hashmap-18ms
class Solution {
  public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        if (root == NULL) {
            return {};
        }
        unordered_map<int, int> dir;
        vector<int> res;
        helper(root, dir);
        int maxValue = (*dir.begin()).second;
        for (auto it = dir.begin(); it != dir.end(); it++) {
            if (it->second > maxValue) {
                maxValue = it->second;
            }
        }
        for (auto it = dir.begin(); it != dir.end(); it++) {
            if (it->second == maxValue) {
                res.push_back(it->first);
            }
        }
        return res;
    }
    int helper(TreeNode *root, unordered_map<int, int> &dir) {
        if (root == NULL) {
            return 0;
        }
        int result =
            root->val + helper(root->left, dir) + helper(root->right, dir);
        dir[result]++;
        return result;
    }
};

//上面的改进版 代码变得短了一点 根据leetcode上的答案的思路改的
//其实本质的思路是一样的
// https://discuss.leetcode.com/topic/77763/short-clean-c-o-n-solution
class Solution_0 {
  public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> dir;
        vector<int> res;
        int maxValue = 0;
        helper(root, dir, maxValue);
        for (auto it = dir.begin(); it != dir.end(); it++) {
            if (it->second == maxValue) {
                res.push_back(it->first);
            }
        }
        return res;
    }
    int helper(TreeNode *root, unordered_map<int, int> &dir, int &maxValue) {
        if (root == NULL) {
            return 0;
        }
        int result = root->val + helper(root->left, dir, maxValue) +
                     helper(root->right, dir, maxValue);
        maxValue = max(++dir[result], maxValue);
        return result;
    }
};