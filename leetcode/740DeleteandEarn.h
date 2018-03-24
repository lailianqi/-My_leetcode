#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来 直接看的答案
// https://leetcode.com/problems/delete-and-earn/discuss/109895/JavaC++-Clean-Code-with-Explanation
class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int m = nums.size(), n = 10001;
        vector<int> values(n, 0);
        for (int num : nums) {
            values[num] += num;
        }
        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

// 第二种方案 和  House Robbers question差不多 参考自LeetCode
// https://leetcode.com/problems/delete-and-earn/discuss/109871/Awesome-Python-4-liner-with-explanation-Reduce-to-House-Robbers-Question
// dp[i] = max(dp[i - 1], dp[i - 2] + value)F
class Solution_0 {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int m = nums.size(), n = 10001;
        vector<int> values(n, 0);
        for (int num : nums) {
            values[num] += num;
        }
        int prev = 0, current = 0;
        for (int i = 0; i < n; i++) {
            int temp = current;
            current = max(current, prev + values[i]);
            prev = temp;
        }
        return current;
    }
};

// 最原始的dp的方案
// https://leetcode.com/problems/delete-and-earn/discuss/109889/Java-Easy-DP-Solution

class Solution_1 {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int m = nums.size(), n = 10001;
        vector<int> values(n, 0), dp(n, 0);
        for (int num : nums) {
            values[num] += num;
        }
        dp[0] = values[0], dp[1] = max(dp[0], values[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + values[i]);
        }
        return dp[n - 1];
    }
};