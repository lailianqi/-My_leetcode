#include <vector>
#include <algorithm>
using namespace std;
//超时的写法，不可能通过的解法
class Solution {
  public:
    int maxCoins(vector<int> &nums) { return helper(nums); }
    int helper(vector<int> nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            if (i == 0 || i == nums.size() - 1) {
                result = max(
                    (i == 0 ? nums[0] * nums[1]
                            : nums[nums.size() - 1] * nums[nums.size() - 2]) +
                        helper(temp),
                    result);
            } else {
                result = max(nums[i - 1] * nums[i] * nums[i + 1] + helper(temp),
                             result);
            }
        }
        return result;
    }
};
//完全错误的写法，思路就错了
class Solution_0 {
  public:
    int maxCoins(vector<int> &nums) {
        vector<int> temp = nums;
        return helper(temp);
    }
    int helper(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int result = 0;
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        if (minIndex == 0 || minIndex == nums.size() - 1) {
            result = result + (minIndex == 0 ? nums[0] * nums[1]
                                             : nums[nums.size() - 1] *
                                                   nums[nums.size() - 2]);
        } else {
            result = result +
                     nums[minIndex - 1] * nums[minIndex] * nums[minIndex + 1];
        }
        nums.erase(nums.begin() + minIndex);
        result += helper(nums);
        return result;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
class Solution_3 {
  public:
    int maxCoins(vector<int> &nums) {
        vector<int> temp(nums.size() + 2, 1);
        int counter = 1;
        for (int x : nums)
            if (x > 0)
                temp[counter++] = x;
        temp[0] = temp[counter++] = 1;
        vector<vector<int>> dp(counter, vector<int>(counter, 0));
        for (int r = 2; r < counter; r++) {
            for (int left = 0; left < counter - r; left++) {
                int right = left + r;
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] =
                        max(dp[left][right],
                            dp[left][k] + temp[left] * temp[k] * temp[right] +
                                dp[k][right]);
                }
            }
        }
        return dp[0][counter - 1];
    }
};

void test() {
    vector<int> t = {3, 1, 5, 8};
    Solution_0 s;
    s.maxCoins(t);
}