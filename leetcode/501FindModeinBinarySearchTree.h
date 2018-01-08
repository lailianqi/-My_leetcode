#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//这题确实没有写出来(因为不能用额外的空间) 直接看的leetcode的答案 不感觉是简单题
//下面是sp大声的解法
// https://discuss.leetcode.com/topic/77335/proper-o-1-space
class Solution {
  public:
    vector<int> findMode(TreeNode *root) {
        int currCount = 0, maxCount = 0, modeCount = 0, currVal = 0;
        helper(root, currCount, maxCount, modeCount, currVal);
        res = vector<int>(modeCount, 0);
        currCount = 0, modeCount = 0, currVal = 0;
        helper(root, currCount, maxCount, modeCount, currVal);
        return res;
    }
    void helper(TreeNode *root, int &currCount, int &maxCount, int &modeCount,
                int &currValue) {
        if (root == NULL)
            return;
        helper(root->left, currCount, maxCount, modeCount, currValue);
        handleValue(root->val, currCount, maxCount, modeCount, currValue);
        helper(root->right, currCount, maxCount, modeCount, currValue);
    }
    void handleValue(int val, int &currCount, int &maxCount, int &modeCount,
                     int &currValue) {
        if (val != currValue) {
            currValue = val;
            currCount = 0;
        }
        currCount++;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        } else if (currCount == maxCount) {
            if (!res.empty()) {
                res[modeCount] = currValue;
            }
            modeCount++;
        }
    }

  private:
    vector<int> res;
};

//自己的一种用了额外空间的方法 并不符合要求 但是代码非常的短
class Solution_0 {
  public:
    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> dir;
        vector<int> res;
        int maxNum = 0;
        helper(root, dir, maxNum);
        for (auto &element : dir) {
            if (element.second == maxNum) {
                res.push_back(element.first);
            }
        }
        return res;
    }
    void helper(TreeNode *root, unordered_map<int, int> &dir, int &maxNum) {
        if (root) {
            maxNum = max(maxNum, ++dir[root->val]);
            helper(root->left, dir, maxNum);
            helper(root->right, dir, maxNum);
        }
    }
};

//中序遍历 自己参照sp的思路又写了一遍
// https://discuss.leetcode.com/topic/77335/proper-o-1-space
class Solution_1 {
  public:
    vector<int> findMode(TreeNode *root) {
        helper(root);
        res = vector<int>(modeCount, 0);
        currCount = 0, modeCount = 0, currval = 0;
        helper(root);
        return res;
    }
    void helper(TreeNode *root) {
        if (root) {
            helper(root->left);
            handleValue(root->val);
            helper(root->right);
        }
    }
    void handleValue(int value) {
        if (value != currval) {
            currval = value;
            currCount = 0;
        }
        currCount++;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        } else if (currCount == maxCount) {
            if (!res.empty()) {
                res[modeCount] = value;
            }
            modeCount++;
        }
    }

  private:
    int maxCount = 0;
    int currval = 0;
    int currCount = 0;
    int modeCount = 0;
    vector<int> res;
};