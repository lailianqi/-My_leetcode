#include <stack>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// https://discuss.leetcode.com/topic/30632/preorder-inorder-and-postorder-iteratively-summarization
//前序,中序,后续的总结
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> nodeStack;
        TreeNode *curNode = root;
        while (!nodeStack.empty() || curNode) {
            if (curNode != NULL) {
                nodeStack.push(curNode);
                res.insert(res.begin(), curNode->val);
                curNode = curNode->right;
            } else {
                TreeNode *node = nodeStack.top();
                nodeStack.pop();
                curNode = node->left;
            }
        }
        return res;
    }
};
//更加简单的写法
// https://discuss.leetcode.com/topic/7427/a-very-concise-solution
class Solution_1 {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root)
            return v;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *p = NULL;
        while (!s.empty()) {
            p = s.top();
            s.pop();
            v.insert(v.begin(), p->val);
            if (p->left)
                s.push(p->left);
            if (p->right)
                s.push(p->right);
        }
        return v;
    }
};
/*

PRE ORDER TRAVERSE

public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.add(p.val);  // Add before going to children
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            p = node.right;
        }
    }
    return result;
}
IN ORDER TRAVERSE

public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            result.add(node.val);  // Add after all left children
            p = node.right;
        }
    }
    return result;
}
POST ORDER TRAVERSE

public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.addFirst(p.val);  // Reverse the process of preorder
            p = p.right;             // Reverse the process of preorder
        } else {
            TreeNode node = stack.pop();
            p = node.left;           // Reverse the process of preorder
        }
    }
    return result;
}
*/

// 牛逼的解法 二刷的时候发现的
// https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization