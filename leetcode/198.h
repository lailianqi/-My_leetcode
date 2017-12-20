#include <vector>
#include <algorithm>
using namespace std;
//自己的写法
class Solution {
  public:
    int rob(vector<int> &nums) {
        int m = nums.size();
        vector<int> dp(m + 1, 0);
        int maxNum = 0;
        for (int i = 1; i <= m; i++) {
            if (i == 1 || i == 2) {
                dp[i] = nums[i - 1];
            } else {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
            }
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;
    }
};

// leetcode的写法，节省了空间
// https://discuss.leetcode.com/topic/11110/c-1ms-o-1-space-very-simple-solution/18?page=1
// https://discuss.leetcode.com/topic/11110/c-1ms-o-1-space-very-simple-solution/48?page=3
class Solution_0 {
  public:
    int rob(vector<int> &nums) {
        int m = nums.size();
        if (m == 0) {
            return 0;
        }
        if (m == 1) {
            nums[0];
        }
        int prevprev = nums[0];
        int prev = max(nums[0], nums[1]);
        for (int i = 1; i < m; i++) {
            int cur = max(prevprev + nums[i], prev);
            prevprev = prev;
            prev = cur;
        }
        return prev;
    }
};
// https://discuss.leetcode.com/topic/14504/9-lines-0ms-o-1-space-c-solution/2
class Solution_1 {
  public:
    int rob(vector<int> &nums) {
        int prev = 0, prevprev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = max(prevprev + nums[i], prev);
            prevprev = prev;
            prev = cur;
        }
        return prev;
    }
};
void test() {
    Solution s;
    vector<int> v = {0};
    s.rob(v);
}