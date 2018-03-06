#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac
// LeetCode的解法其实差不多 思想应该是一模一样的
// https://leetcode.com/problems/find-pivot-index/discuss/109249/Java-6-liner
// https://leetcode.com/problems/find-pivot-index/discuss/109255/Short-Python-O(n)-time-O(1)-space-with-Explanation

class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int m = nums.size();
        vector<int> sum(m, 0);
        for (int i = 0; i < m; i++) {
            sum[i] += (i == 0 ? 0 : sum[i - 1]) + nums[i];
        }
        for (int i = 0; i < m; i++) {
            if (sum[i] - nums[i] == sum[m - 1] - sum[i]) {
                return i;
            }
        }
        return -1;
    }
};

// leetcode的解法 另外的一种写法
// https://leetcode.com/problems/find-pivot-index/discuss/109274/JavaC++-Clean-Code
class Solution_0 {
  public:
    int pivotIndex(vector<int> &nums) {
        int m = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, leftSum = 0; i < m; i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
void test() {
    Solution s;
    vector<int> a = {-1, -1, -1, -1, -1, -1};
    s.pivotIndex(a);
}