#include <vector>
using namespace std;
//自己并没有从该问题 House Robber I的想到House Robber II的答案
// leetcode的答案
// https://discuss.leetcode.com/topic/14504/9-lines-0ms-o-1-space-c-solution
// https://discuss.leetcode.com/topic/14375/simple-ac-solution-in-java-in-o-n-with-explanation
/*
This problem is a little tricky at first glance. However, if you have finished
the House Robber problem, this problem can simply be decomposed into two House
Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot
rob them together and thus the solution is now the maximum of
Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
The code is as follows. Some edge cases (n < 2) are handled explicitly.
*/
class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return n ? nums[0] : 0;
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
    int rob(vector<int> &nums, int left, int right) {
        int prev = 0, prevprev = 0;
        for (int i = left; i <= right; i++) {
            int cur = max(prevprev + nums[i], prev);
            prevprev = prev;
            prev = cur;
        }
        return prev;
    }
};