#include <algorithm>
#include <deque>
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

// 自己的第一种解法 成功ac
// LeetCode上面和这个解法思想差不多的答案
// https://leetcode.com/problems/maximum-binary-tree/discuss/106194/JavaC++-Simple-recursive-method.
// https://leetcode.com/problems/maximum-binary-tree/discuss/106149/Java-solution-recursion
class Solution {
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return helper(nums, 0, nums.size());
    }
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return NULL;
        }
        int index = max_element(nums.begin() + left, nums.begin() + right) -
                    nums.begin();
        TreeNode *root = new TreeNode(nums[index]);
        root->left = helper(nums, left, index);
        root->right = helper(nums, index + 1, right);
        return root;
    }
};
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    /
//      2  0
//        \
//         1

// 另外的一种解法 值得学习
// https://leetcode.com/problems/maximum-binary-tree/discuss/106156/Java-worst-case-O(N)-solution
class Solution_0 {
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        deque<TreeNode *> st;
        for (int i = 0; i < nums.size(); i++) {
            TreeNode *curr = new TreeNode(nums[i]);
            while (!st.empty() && st.back()->val < nums[i]) {
                curr->left = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                st.back()->right = curr;
            }
            st.push_back(curr);
        }
        return st.front();
    }
};