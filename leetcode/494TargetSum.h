#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <map>
using namespace std;
//自己的第一种解法 这种解法超时 所以过不了ac
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int res = 0;
        helper(nums, 0, 0, S, res);
        return res;
    }
    void helper(vector<int> nums, int index, int sum, int S, int &res) {
        if (index == nums.size()) {
            if (sum == S) {
                res++;
            }
            return;
        }
        helper(nums, index + 1, sum - nums[index], S, res);
        helper(nums, index + 1, sum + nums[index], S, res);
    }
};
//这题的备忘录的解法和自己以前写的模式非常的不一样
//所以这道题备忘录的解法自己没有写出来
//直接看的leetcode的答案
// https://discuss.leetcode.com/topic/76245/java-simple-dfs-with-memorization
// https://discuss.leetcode.com/topic/76245/java-simple-dfs-with-memorization/12
class Solution_0 {
  public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int res = 0, m = nums.size();
        map<string, int> dir;
        return helper(nums, 0, 0, S, dir);
    }
    int helper(vector<int> nums, int index, int sum, int S,
               map<string, int> &dir) {
        string hashcode = to_string(index) + "->" + to_string(sum);
        if (dir.count(hashcode)) {
            return dir[hashcode];
        }
        if (index == nums.size()) {
            if (sum == S) {
                return 1;
            }
            return 0;
        }
        int left = helper(nums, index + 1, sum - nums[index], S, dir);
        int right = helper(nums, index + 1, sum + nums[index], S, dir);
        return dir[hashcode] = left + right;
    }
};

//第三种解法 来自leetcode的答案 现在测试也是超时的
// https://discuss.leetcode.com/topic/76201/java-short-dfs-solution
class Solution_1 {
  public:
    int findTargetSumWays(vector<int> &nums, int S) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0, m = nums.size();
        vector<int> sums(m, 0);
        sums[m - 1] = nums[m - 1];
        for (int i = m - 2; i >= 0; i--)
            sums[i] = sums[i + 1] + nums[i];
        helper(nums, sums, 0, S, res);
        return res;
    }
    void helper(vector<int> nums, vector<int> &sums, int index, int target,
                int &res) {
        if (index == nums.size()) {
            if (target == 0) {
                res++;
            }
            return;
        }
        if (sums[index] < abs(target))
            return;
        helper(nums, sums, index + 1, target - nums[index], res);
        helper(nums, sums, index + 1, target + nums[index], res);
    }
};

// 现在介绍最牛逼的方案 来自与leetcode的答案 通过数学的思维来分析答案
// 程序的某部分来自leetcode的416题
// https://discuss.leetcode.com/topic/76243/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation/2
class Solution_2 {
  public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
    }
    int subsetSum(vector<int> &nums, int S) {
        int dp[S + 1] = {0};
        dp[0] = 1;
        for (int n : nums)
            for (int i = S; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[S];
    }
};
void test() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    s.findTargetSumWays(nums, 3);
}