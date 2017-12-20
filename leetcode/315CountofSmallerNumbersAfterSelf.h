#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//没有写出来
// BST的写法
// https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst?page=1
// http://www.cnblogs.com/grandyang/p/5078490.html
class Solution {
  public:
    class TreeNode {
      public:
        TreeNode *left, *right;
        int val, smaller;
        TreeNode(int val, int smaller)
            : val(val), smaller(smaller), left(NULL), right(NULL) {}
    };
    int insert(TreeNode *&root, int val) {
        if (root == NULL) {
            root = new TreeNode(val, 0);
            return 0;
        }
        if (root->val > val) {
            root->smaller++;
            return insert(root->left, val);
        } else {
            return root->smaller + insert(root->right, val) +
                   (root->val < val ? 1 : 0);
        }
    }
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> res(nums.size(), 0);
        TreeNode *root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};
//最简单的写法
// http://www.cnblogs.com/grandyang/p/5078490.html
//由300题的解法延伸
class Solution_0 {
  public:
    vector<int> countSmaller(vector<int> &nums) {
        int m = nums.size();
        vector<int> res(m, 0), temp;
        for (int i = m - 1; i >= 0; i--) {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            res[i] = it - temp.begin();
            temp.insert(temp.begin() + res[i], nums[i]);
        }
        return res;
    }
};

// leetcode的答案 mergesort的解法
// https://discuss.leetcode.com/topic/31288/c-o-nlogn-time-o-n-space-mergesort-solution-with-detail-explanation
// https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst/12
class Solution_1 {
  public:
    class TreeNode {
      public:
        TreeNode *left, *right;
        int val, smaller;
        TreeNode(int val, int smaller)
            : val(val), smaller(smaller), left(NULL), right(NULL) {}
    };
    vector<int> countSmaller(vector<int> &nums) {
        if (nums.size() == 0)
            return vector<int>();
        int m = nums.size();
        vector<int> res(m, 0);
        TreeNode *root = NULL;
        for (int i = m - 1; i >= 0; --i)
            root = insert(root, nums[i], i, res, 0);
        return res;
    }
    TreeNode *insert(TreeNode *root, int val, int index, vector<int> &res,
                     int preSum) {
        if (root == NULL) {
            root = new TreeNode(val, 0);
            res[index] = preSum;
            return root;
        }
        if (root->val > val) {
            root->smaller++;
            root->left = insert(root->left, val, index, res, preSum);
        } else {
            root->right =
                insert(root->right, val, index, res,
                       preSum + root->smaller + (root->val < val ? 1 : 0));
        }
        return root;
    }
};

//上面的方法 换一种写法
class Solution_2 {
  public:
    class TreeNode {
      public:
        TreeNode *left, *right;
        int val, smaller;
        TreeNode(int val, int smaller)
            : val(val), smaller(smaller), left(NULL), right(NULL) {}
    };
    vector<int> countSmaller(vector<int> &nums) {
        if (nums.size() == 0)
            return vector<int>();
        int m = nums.size();
        vector<int> res;
        TreeNode *root = NULL;
        for (int i = m - 1; i >= 0; --i)
            root = insert(root, nums[i], res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    TreeNode *insert(TreeNode *root, int val, vector<int> &res, int preSum) {
        if (root == NULL) {
            root = new TreeNode(val, 0);
            res.push_back(preSum);
            return root;
        }
        if (root->val > val) {
            root->smaller++;
            root->left = insert(root->left, val, res, preSum);
        } else {
            root->right =
                insert(root->right, val, res,
                       preSum + root->smaller + (root->val < val ? 1 : 0));
        }
        return root;
    }
};