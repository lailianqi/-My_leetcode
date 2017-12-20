#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己的写法
class Solution {
  public:
    int maxDepthValue = 0;
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        traverse(root, 0);
        return maxDepthValue + 1;
    }
    void traverse(TreeNode *root, int depth) {
        if (root != NULL) {
            if (depth > maxDepthValue) {
                maxDepthValue = depth;
            }
            traverse(root->left, depth + 1);
            traverse(root->right, depth + 1);
        }
    }
};

class Solution_0 {
  public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};