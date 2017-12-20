#include <string>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//参照leetcode的答案
// https://discuss.leetcode.com/topic/8410/divide-and-conquer-f-i-g-i-1-g-n-i
class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode *>();
        }
        return doGenerateTrees(1, n);
    }
    vector<TreeNode *> doGenerateTrees(int s, int e) {
        vector<TreeNode *> res;
        if (s > e) {
            res.push_back(NULL); // empty tree
            return res;
        }
        for (int i = s; i <= e; i++) {
            vector<TreeNode *> leftPart = doGenerateTrees(s, i - 1);
            vector<TreeNode *> rightPart = doGenerateTrees(i + 1, e);
            for (auto a : leftPart) {
                for (auto b : rightPart) {
                    TreeNode *root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};



// https://discuss.leetcode.com/topic/2940/java-solution-with-dp/16
//https://discuss.leetcode.com/topic/7762/accepted-iterative-java-solution
// DP的写法
/*
public List<TreeNode> generateTrees(int n) {
        List<TreeNode>[] res = new List[n+1];
        res[0] = new ArrayList();
        if(n == 0) return res[0];
        res[0].add(null);
        res[1] = new ArrayList();
        res[1].add(new TreeNode(1));
        for(int i=2;i<=n;i++){
            res[i] = new ArrayList();
                for(int j=1;j<=i;j++){
                        for(TreeNode nodeL: res[j-1]){
                                for(TreeNode nodeR: res[i-j]){
                                        TreeNode node = new TreeNode(j);
                                        node.left = nodeL;
                                        node.right = clone(nodeR, j);
                                        res[i].add(node);
                                }
                        }
                }
        }
        return res[n];
}


static TreeNode clone(TreeNode node, int offset){
        if(node == null) return null;
        TreeNode newNode = new TreeNode(node.val + offset);
        newNode.left = clone(node.left, offset);
        newNode.right = clone(node.right, offset);
        return newNode;
}*/