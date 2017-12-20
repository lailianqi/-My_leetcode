#include <string>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
in-order:   4  2  5 (1) 6 7 3 8
pre-order: (1) 2  4  5  3 7 6 8
*/
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeTrack(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode *buildTreeTrack(vector<int> &preorder, vector<int> &inorder,
                             int preStart, int inStart, int inEnd) {
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }
        root->left = buildTreeTrack(preorder, inorder, preStart + 1, inStart,
                                    inIndex - 1);
        root->right =
            buildTreeTrack(preorder, inorder, preStart + inIndex - inStart + 1,
                           inIndex + 1, inEnd);
        return root;
    }
};

class Solution_1 {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                         inorder.size() - 1, inMap);
    }
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int, int> &inMap) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        root->left =
            buildTree(preorder, preStart + 1, preStart + inRoot - inStart,
                      inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + inRoot - inStart + 1,
                                preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};