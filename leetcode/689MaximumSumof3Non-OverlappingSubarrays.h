#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 这种解法是超时的
class Solution {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int m = nums.size(), res = 0;
        vector<int> resIndex(3, 0);
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i <= m - k; i++) {
            dp[i][i] = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                dp[i][j] = dp[i][j - 1] + nums[j];
            }
        }
        for (int i = 0; i <= m - 3 * k; i++) {
            for (int j = i + k; j <= m - 2 * k; j++) {
                for (int t = j + k; t <= m - k; t++) {
                    if (dp[i][i + k - 1] + dp[j][j + k - 1] + dp[t][t + k - 1] >
                        res) {
                        res = dp[i][i + k - 1] + dp[j][j + k - 1] +
                              dp[t][t + k - 1];
                        resIndex = {i, j, t};
                    }
                }
            }
        }
        return resIndex;
    }
};

// 来自LeetCode的解法 老实说 已经是找的到的最好的解法 虽然还是非常的乱
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108231/C++Java-DP-with-explanation-O(n)
class Solution_0 {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int m = nums.size(), maxValue = 0;
        vector<int> res;
        vector<int> sum(m + 1, 0), posLeft(m, 0), posRight(m, m - k);
        for (int i = 0; i < m; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        // left的部分
        for (int i = k, bestSum = sum[k] - sum[0]; i < m; i++) {
            if (sum[i + 1] - sum[i + 1 - k] > bestSum) {
                posLeft[i] = i + 1 - k;
                bestSum = sum[i + 1] - sum[i + 1 - k];
            } else {
                posLeft[i] = posLeft[i - 1];
            }
        }

        // right的部分
        for (int i = m - k - 1, bestSum = sum[m] - sum[m - k]; i >= 0; i--) {
            if (sum[i + k] - sum[i] >= bestSum) {
                posRight[i] = i;
                bestSum = sum[i + k] - sum[i];
            } else {
                posRight[i] = posRight[i + 1];
            }
        }

        for (int i = k; i <= m - 2 * k; i++) {
            int left = posLeft[i - 1], right = posRight[i + k];
            int threeSum = sum[left + k] - sum[left] + sum[i + k] - sum[i] +
                           sum[right + k] - sum[right];
            if (threeSum > maxValue) {
                maxValue = threeSum;
                res = {left, i, right};
            }
        }
        return res;
    }
};

// 来自LeetCode的解法 上面的简化版 写的非常的不错 上面简直是狗屎
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108258/O(n)-C++-Solution
class Solution_1 {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); i++)
            sum[i + 1] = sum[i] + nums[i];

        vector<pair<int, int>> forward(nums.size());
        forward[0] = make_pair(sum[k] - sum[0], 0);
        for (int i = 1; i <= (int)nums.size() - k; i++) {
            int t = sum[i + k] - sum[i];
            forward[i] =
                (forward[i - 1].first >= t) ? forward[i - 1] : make_pair(t, i);
        }

        vector<pair<int, int>> backward(nums.size() + 1);
        for (int i = (int)nums.size() - k; i >= 0; i--) {
            int t = sum[i + k] - sum[i];
            backward[i] =
                (backward[i + 1].first > t) ? backward[i + 1] : make_pair(t, i);
        }

        int ansSum = 0;
        vector<int> ans(3);
        for (int i = k; i <= (int)nums.size() - k * 2; i++) {
            int t = forward[i - k].first + backward[i + k].first + sum[i + k] -
                    sum[i];
            if (ansSum < t) {
                ansSum = t;
                ans = vector<int>{forward[i - k].second, i,
                                  backward[i + k].second};
            }
        }

        return ans;
    }
};

// 还有一种最超前的写法 最牛逼的写法
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108238/Python-o(n)-time-o(1)-space.-Greedy-solution.

void test() {
    Solution s;
    vector<int> nums = {7, 13, 20, 19, 19, 2, 10, 1, 1, 19};
    s.maxSumOfThreeSubarrays(nums, 3);
}