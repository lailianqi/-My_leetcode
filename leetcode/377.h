#include <vector>
using namespace std;
//最蠢的做法 会超时
//增加备忘录的解法就不会超时了
// leetcode的解法类似
// https://discuss.leetcode.com/topic/52302/1ms-java-dp-solution-with-detailed-explanation
class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        helper(nums, target, dp);
        return dp[target];
    }
    int helper(vector<int> &nums, int target, vector<int> &dp) {
        if (dp[target] != -1) {
            return dp[target];
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i])
                result += helper(nums, target - nums[i], dp);
        }
        dp[target] = result;
        return result;
    }
};
// dp的写法
class Solution_0 {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};