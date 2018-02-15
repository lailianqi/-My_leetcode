#include <queue>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//自己的第一种方案 成功ac
//答案的思路和写法和LeetCode的最佳答案基本上一模一样
class Solution {
  public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> treeQueue;
        //不用判NULL的操作，因为题目给的数据要求就是一个NoneEmpty的tree
        treeQueue.push(root);
        vector<double> res;
        while (!treeQueue.empty()) {
            int m = treeQueue.size();
            double sum = 0;
            for (int i = 0; i < m; i++) {
                TreeNode *curr = treeQueue.front();
                sum += curr->val;
                treeQueue.pop();
                if (curr->left) {
                    treeQueue.push(curr->left);
                }
                if (curr->right) {
                    treeQueue.push(curr->right);
                }
            }
            res.push_back(sum / m);
        }
        return res;
    }
};