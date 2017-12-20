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
//队列的写法
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> answers;
        if (root == NULL)
            return answers;
        queue<TreeNode *> queueInstance;
        queueInstance.push(root);
        while (!queueInstance.empty()) {
            int sizeNum = queueInstance.size();
            vector<int> ans;
            for (int i = 0; i < sizeNum; i++) {
                TreeNode *p = queueInstance.front();
                queueInstance.pop();
                if (p->left != NULL) {
                    queueInstance.push(p->left);
                }
                if (p->right != NULL) {
                    queueInstance.push(p->right);
                }
                ans.push_back(p->val);
            }
            answers.push_back(ans);
        }
        return answers;
    }
};