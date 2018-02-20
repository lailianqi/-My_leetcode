#include <algorithm>
#include <vector>
using namespace std;

// 好题 和300题是联动的
// leetcode的答案
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107293/JavaC++-Simple-dp-solution-with-explanation
class Solution {
  public:
    int findNumberOfLIS(vector<int> &nums) {
        int result = 0, m = nums.size(), maxLength = 1;
        vector<int> dp(m, 1), cnt(m, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        for (int i = 0; i < m; i++) {
            if (dp[i] == maxLength)
                result += cnt[i];
        }
        return result;
    }
};

// leetcode的答案 上面的改进版
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107293/JavaC++-Simple-dp-solution-with-explanation

class Solution_0 {
  public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size(), res = 0, max_len = 0;
        // dp[i]: {length, number of LIS which ends with nums[i]}
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                    if (dp[i].first < dp[j].first + 1)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if (max_len == dp[i].first)
                res += dp[i].second;
            if (max_len < dp[i].first) {
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
};