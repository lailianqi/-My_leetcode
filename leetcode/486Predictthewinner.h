#include <vector>
#include <algorithm>
using namespace std;
//直接看的答案 没有想到方案  因为不知道如何轮流的交替
// leetcode的答案
// https://discuss.leetcode.com/topic/76830/java-9-lines-dp-solution-easy-to-understand-with-improvement-to-o-n-space-complexity?page=1

class Solution {
  public:
    bool PredictTheWinner(vector<int> &nums) {
        int m = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int step = 1; step <= m; step++) {
            for (int i = 0; i < m - step + 1; i++) {
                int j = i + step - 1;
                dp[i][j] = i == j ? nums[i] : max(nums[i] - dp[i + 1][j],
                                                  nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][m - 1] >= 0;
    }
};

//自己对上面的空间优化版
//下面是leetcode上对面的空间优化版的链接 与之比较 自己的空间优化版本更加的优秀
// https://discuss.leetcode.com/topic/76830/java-9-lines-dp-solution-easy-to-understand-with-improvement-to-o-n-space-complexity?page=1
class Solution_0 {
  public:
    bool PredictTheWinner(vector<int> &nums) {
        int m = nums.size();
        vector<int> dp(m, 0);
        for (int step = 1; step <= m; step++) {
            for (int i = 0; i < m - step + 1; i++) {
                dp[i] = step == 1 ? nums[i] : max(nums[i] - dp[i + 1],
                                                  nums[i + step - 1] - dp[i]);
            }
        }
        return dp[0] >= 0;
    }
};

// 还有一种写法 来自leetcode 直接用的递归 更加的简洁 但是速度太慢
// 所以加了备忘录的解法 也是来自于同一个链接
// https://discuss.leetcode.com/topic/76312/java-1-line-recursion-solution
class Solution_1 {
  public:
    bool PredictTheWinner(vector<int> &nums) {
        int m = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        return helper(nums, 0, m - 1, dp) >= 0;
    }
    int helper(vector<int> &nums, int left, int right,
               vector<vector<int>> &dp) {
        if (dp[left][right] != INT_MIN) {
            return dp[left][right];
        }
        return dp[left][right] =
                   left == right
                       ? nums[left]
                       : max(nums[left] - helper(nums, left + 1, right, dp),
                             nums[right] - helper(nums, left, right - 1, dp));
    }
};
void test() {
    Solution s;
    vector<int> nums = {1, 5, 2};
    s.PredictTheWinner(nums);
}