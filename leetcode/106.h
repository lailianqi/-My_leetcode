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
Inorder:　　 　11　　4　　5　　13　　8　　9
Postorder:　　11　　4　　13　　9　　8　　5　　
*/

class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1, inMap);
    }
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd,
                        vector<int> &postorder, int postStart, int postEnd,
                        map<int, int> &inMap) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        root->left =
            buildTree(inorder, inStart, inRoot - 1, postorder, postStart,
                      postEnd - (inEnd - inRoot + 1), inMap);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder,
                                postEnd - (inEnd - inRoot), postEnd - 1, inMap);
        return root;
    }
};