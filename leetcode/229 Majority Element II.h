#include <vector>
#include <algorithm>
using namespace std;
//没有想出来
// leetcode的答案 称为Boyer-Moore Majority Vote algorithm generalization算法
// https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration
class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                candidate1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                candidate2 = nums[i];
            } else {
                count1--;
                count2--;
            }
        }
        if (count(nums.begin(), nums.end(), candidate1) > nums.size() / 3)
            res.push_back(candidate1);
        if (count(nums.begin(), nums.end(), candidate2) > nums.size() / 3)
            res.push_back(candidate2);
        return res;
    }
};