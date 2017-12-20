#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
//一开始 并没有想通  看了答案 发现是以前最熟悉的01背包问题  真是非常的惭愧
// https://www.cnblogs.com/grandyang/p/5951422.html
// https://discuss.leetcode.com/topic/67539/0-1-knapsack-detailed-explanation
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;
        if (sum % 2 == 1) {
            return false;
        }
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

// bit的解法 非常的风骚
// leetcode的答案
// https://discuss.leetcode.com/topic/62334/simple-c-4-line-solution-using-a-bitset/17
// https://discuss.leetcode.com/topic/62334/simple-c-4-line-solution-using-a-bitset
class Solution_0 {
  public:
    bool canPartition(vector<int> &nums) {
        bitset<100001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            bits |= bits << nums[i];
        }
        return !(sum & 1) && bits[sum >> 1];
    }
};