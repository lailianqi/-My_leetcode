#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

// 我的第一种方法 超时 所以没写出来完全正确的答案
class Solution {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % k) {
            return false;
        }
        int averNum = numSum / k, m = nums.size();
        vector<bool> visited(m, false);
        return helper(nums, visited, k, 0, averNum);
    }

    bool helper(vector<int> &nums, vector<bool> &visited, int k, int current,
                int target) {
        if (current > target) {
            return false;
        }
        if (k == 1) {
            return true;
        }
        if (current == target) {
            return helper(nums, visited, k - 1, 0, target);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (helper(nums, visited, k, current + nums[i], target)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};

// 来自LeetCode的改进版 基于我超时方案的改进版
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/108730/JavaC++Straightforward-dfs-solution
class Solution_0 {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % k) {
            return false;
        }
        int averNum = numSum / k, m = nums.size();
        vector<bool> visited(m, false);
        return helper(nums, visited, k, 0, 0, averNum);
    }

    bool helper(vector<int> &nums, vector<bool> &visited, int k, int start,
                int current, int target) {
        if (current > target) {
            return false;
        }
        if (k == 1) {
            return true;
        }
        if (current == target) {
            return helper(nums, visited, k - 1, 0, 0, target);
        }
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (helper(nums, visited, k, i + 1, current + nums[i],
                           target)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};

// LeetCode的答案 上面的改好版
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/108730/JavaC++Straightforward-dfs-solution
class Solution_1 {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % k) {
            return false;
        }
        int averNum = numSum / k, m = nums.size();
        vector<bool> visited(m, false);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, visited, k, 0, 0, averNum);
    }

    bool helper(vector<int> &nums, vector<bool> &visited, int k, int start,
                int current, int target) {
        if (current > target) {
            return false;
        }
        if (k == 1) {
            return true;
        }
        if (current == target) {
            return helper(nums, visited, k - 1, 0, 0, target);
        }
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (helper(nums, visited, k, i + 1, current + nums[i],
                           target)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};

// 背包的解法 leetcode的原解法是错的  我改写了他的方案  还是过不去 还是错的
// 错误的链接在下面
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/108745/discrete-knapsack-problem-using-dp
class Solution_2 {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % k) {
            return false;
        }
        int averNum = numSum / k, m = nums.size();
        vector<int> dp(numSum + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = numSum; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        for (int i = 1; i <= k; i++) {
            if (dp[averNum * k] != averNum * k) {
                return false;
            }
        }
        return true;
    }
};