#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//一开始打算用dp写 发现没有写出来
// leetcode的答案 采用的dp 但是不是最佳的答案 最佳的答案采用的是binary search
// https://discuss.leetcode.com/topic/61405/dp-java
/*
dp[s,j] is the solution for splitting subarray n[j]...n[L-1] into s parts.
dp[s+1,i] = min{ max(dp[s,j], n[i]+...+n[j-1]) }, i+1 <= j <= L-s
*/
// https://discuss.leetcode.com/topic/61405/dp-java/8
class Solution {
  public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        vector<int> sumQuery(n + 1, 0), dp(n + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sumQuery[i + 1] = sumQuery[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i] = sumQuery[n] - sumQuery[i];
        }
        for (int s = 2; s <= m; s++) {
            for (int i = 0; i <= n - s; i++) {
                dp[i] = INT_MAX;
                for (int j = i + 1; j <= n - s + 1; j++) {
                    int t = max(dp[j], sumQuery[j] - sumQuery[i]);
                    if (t > dp[i]) {
                        break;
                    }
                    dp[i] = min(dp[i], t);
                }
            }
        }
        return dp[0];
    }
};
// dp的改进版 写成熟悉的版本 自己写的
class Solution_0 {
  public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        vector<int> sumQuery(n + 1, 0);
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        for (int i = 0; i < nums.size(); i++) {
            sumQuery[i + 1] = sumQuery[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[1][i] = sumQuery[i + 1];
        }
        for (int step = 2; step <= m; step++) {
            for (int i = step - 1; i < n; i++) {
                dp[step][i] = INT_MAX;
                for (int j = 0; j < i; j++) {
                    int t =
                        max(dp[step - 1][j], sumQuery[i + 1] - sumQuery[j + 1]);
                    if (t > dp[step][i]) {
                        break;
                    }
                    dp[step][i] = min(dp[step][i], t);
                }
            }
        }
        return dp[m][n - 1];
    }
};
// dp的终极版 网上的答案
// https://www.cnblogs.com/grandyang/p/5933787.html

// leetcode 二分查找的解法
// https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java

// 二分查找的不同的形式 需要去注意
// https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java/23?page=2
class Solution_1 {
  public:
    int splitArray(vector<int> &nums, int m) {
        int maxValue = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxValue = max(maxValue, nums[i]);
            sum += nums[i];
        }
        if (m == 1)
            return (int)sum;
        long left = maxValue, right = sum;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (validSplit(mid, nums, m)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (int)left;
    }
    bool validSplit(long target, vector<int> nums, int m) {
        int counter = 1;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > target) {
                sum = nums[i];
                counter++;
                if (counter > m) {
                    return false;
                }
            }
        }
        return true;
    }
};