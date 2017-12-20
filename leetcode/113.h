#include <cmath>
#include <string>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> answers;
        vector<int> answer;
        doPathSum(root, sum, answer, answers);
        return answers;
    }
    void doPathSum(TreeNode *root, int sum, vector<int> answer,
                   vector<vector<int>> &answers) {
        if (root == NULL) {
            return;
        }
        answer.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            answers.push_back(answer);
        }
        doPathSum(root->left, sum - root->val, answer, answers);
        doPathSum(root->right, sum - root->val, answer, answers);
    }
};
//这样子效率更高
class Solution_0 {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> answers;
        vector<int> answer;
        doPathSum(root, sum, answer, answers);
        return answers;
    }
    void doPathSum(TreeNode *root, int sum, vector<int> &answer,
                   vector<vector<int>> &answers) {
        if (root == NULL) {
            return;
        }
        answer.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            answers.push_back(answer);
        }
        doPathSum(root->left, sum - root->val, answer, answers);
        doPathSum(root->right, sum - root->val, answer, answers);
        answer.pop_back();
    }
};