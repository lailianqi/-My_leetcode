#include <string>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的第一种解法 成功ac 如果对时间要求高的话会超时 想不到在oj判断中效率不错
// Oj的时间要求不高
class Solution {
  public:
    int pathSum(TreeNode *root, int sum) {
        int res = 0;
        helper(root, sum, res);
        return res;
    }
    void helper(TreeNode *root, int sum, int &res) {
        if (root) {
            traver(root, sum, res);
            helper(root->left, sum, res);
            helper(root->right, sum, res);
        }
    }
    void traver(TreeNode *root, int sum, int &res) {
        if (root) {
            if (sum - root->val == 0) {
                res++;
            }
            traver(root->left, sum - root->val, res);
            traver(root->right, sum - root->val, res);
        }
    }
};

//自己对上面解法的改进版
// leetcode的答案与这个类似
// https://discuss.leetcode.com/topic/64461/simple-java-dfs
class Solution_0 {
  public:
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        return pathSum(root->left, sum) + pathSum(root->right, sum) +
               helper(root, sum);
    }
    int helper(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        return (root->val == sum ? 1 : 0) +
               helper(root->left, sum - root->val) +
               helper(root->right, sum - root->val);
    }
};

//还有一种最牛逼的写法 leetcode的解法 运行的速度非常的快
// https://discuss.leetcode.com/topic/64526/17-ms-o-n-java-prefix-sum-method
class Solution_1 {
  public:
    int pathSum(TreeNode *root, int sum) {
        map<int, int> preSum;
        preSum[0] = 1;
        return helper(root, 0, sum, preSum);
    }
    int helper(TreeNode *root, int currSum, int target, map<int, int> &preSum) {
        if (root == NULL) {
            return 0;
        }
        currSum += root->val;
        int res = preSum[currSum - target];
        preSum[currSum]++;
        res += helper(root->left, currSum, target, preSum) +
               helper(root->right, currSum, target, preSum);
        preSum[currSum]--;
        return res;
    }
};