#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
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
            answers.insert(answers.begin(), ans);
        }
        return answers;
    }
};

class Solution_0 {
  public:
    /*
  public List<List<Integer>> levelOrderBottom(TreeNode root) {
              List<List<Integer>> wrapList = new LinkedList<List<Integer>>();
              levelMaker(wrapList, root, 0);
              return wrapList;
          }

          public void levelMaker(List<List<Integer>> list, TreeNode root, int
  level) {
              if(root == null) return;
              if(level >= list.size()) {
                  list.add(0, new LinkedList<Integer>());
              }
              levelMaker(list, root.left, level+1);
              levelMaker(list, root.right, level+1);
              list.get(list.size()-level-1).add(root.val);
          }*/
};