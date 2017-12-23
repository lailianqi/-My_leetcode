#include <cmath>
#include <vector>
using namespace std;
/*
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

//方法没有想到 所以无法按照题目的要求写出来
//一开始题目理解错了 res的空间其实没有包含在里面
// leetcode的第一种解法 空间的要求其实并没有满足到 还是用了额外的空间
// https://discuss.leetcode.com/topic/64735/java-simple-solution?page=1
class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                res.push_back(index + 1);
            }
            nums[index] = -nums[index];
        }
        return res;
    }
};
//上面解法的另外的一种形式
class Solution_0 {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -nums[index];
            if (nums[index] > 0) {
                res.push_back(index + 1);
            }
        }
        return res;
    }
};

// LeetCode的解法  第三种解法 提供了一种完全不同的思路
// 画图后可以清晰思路 明白过程
// https://discuss.leetcode.com/topic/64759/very-simple-c-solution?page=1
class Solution_1 {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};
