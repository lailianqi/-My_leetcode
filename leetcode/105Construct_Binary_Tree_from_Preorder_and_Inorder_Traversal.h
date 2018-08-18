#include <map>
#include <string>
#include <vector>
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

// 这题第一遍的时候肯定写不来 第二遍的时候添加了官方的网址
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34562/Sharing-my-straightforward-recursive-solution
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

// 下面是来自于LeetCode的答案
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34541/5ms-Java-Clean-Solution-with-Caching
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

// 用长度的方法写 参考自LeetCode 也是自己最初的思路
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution
class Solution_2 {
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return helper(pre, vin, 0, 0, pre.size());
    }
    TreeNode *helper(vector<int> &pre, vector<int> &vin, int preStart,
                     int inStart, int length) {
        if (length == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[preStart]);
        if (length == 1) {
            return root;
        }
        int pos = find(vin.begin() + inStart, vin.begin() + inStart + length,
                       pre[preStart]) -
                  vin.begin();
        root->left = helper(pre, vin, preStart + 1, inStart, pos - inStart);
        root->right = helper(pre, vin, preStart + (pos - inStart) + 1, pos + 1,
                             (length - 1 - (pos - inStart)));
        return root;
    }
};

// --------------------------------二刷
class Solution_3 {
  public:
    map<int, int> dir;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int m = preorder.size(), n = inorder.size();
        for (int i = 0; i < m; i++) {
            dir[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, m - 1, 0, n - 1);
    }
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int pre_start,
                     int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int split = dir[preorder[pre_start]];
        root->left = helper(preorder, inorder, pre_start + 1,
                            split - in_start + pre_start, in_start, split - 1);
        root->right =
            helper(preorder, inorder, split - in_start + pre_start + 1, pre_end,
                   split + 1, in_end);
        return root;
    }
};