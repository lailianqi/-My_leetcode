#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//我的第一种解法 完美ac
class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        if (root == NULL)
            return {};
        vector<int> res;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode *temp = nodeQueue.front();
                nodeQueue.pop();
                maxValue = max(maxValue, temp->val);
                if (temp->left)
                    nodeQueue.push(temp->left);
                if (temp->right)
                    nodeQueue.push(temp->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};