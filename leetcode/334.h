#include <vector>
#include <stack>
#include <climits>
using namespace std;
//脑子迷糊了 这题应该轻松写出来的
// https://discuss.leetcode.com/topic/37281/clean-and-short-with-comments-c
//记录状态是这题的重点
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (first >= nums[i]) {
                first = nums[i];
            } else if (second >= nums[i]) {
                second = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};