#include <queue>
#include <deque>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> answers;
        bool leftToRight = true;
        if (root == NULL)
            return answers;
        queue<TreeNode *> dequeIntance;
        dequeIntance.push(root);
        while (!dequeIntance.empty()) {
            int sizeNum = dequeIntance.size();
            vector<int> ans(sizeNum);
            for (int i = 0; i < sizeNum; i++) {
                TreeNode *p = dequeIntance.front();
                dequeIntance.pop();
                int index = (leftToRight) ? i : (sizeNum - 1 - i);
                ans[index] = p->val;
                if (p->left != NULL) {
                    dequeIntance.push(p->left);
                }
                if (p->right != NULL) {
                    dequeIntance.push(p->right);
                }
            }
            answers.push_back(ans);
            leftToRight = !leftToRight;
        }
        return answers;
    }
};

class Solution_0 {
  public:
    vector<vector<int>> answers;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        traverse(root, 0);
        return answers;
    }
    void traverse(TreeNode *root, int depth) {
        if (root != NULL) {
            if (answers.size() <= depth) {
                vector<int> answer;
                answers.push_back(answer);
            }
            if (depth & 1) {
                answers[depth].insert(answers[depth].begin(), root->val);
            } else {
                answers[depth].push_back(root->val);
            }
            traverse(root->left, depth + 1);
            traverse(root->right, depth + 1);
        }
    }
};