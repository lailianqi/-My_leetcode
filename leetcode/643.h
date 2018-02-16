#include <algorithm>
#include <vector>
using namespace std;

// 自己的第一种方案 一次ac
// LeetCode没有比这个写的好的答案
class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        int m = nums.size();
        double sum = 0, res = INT_MIN;
        for (int i = 0; i < m; i++) {
            sum += nums[i];
            if (i >= k - 1) {
                res = max(res, sum / k);
                sum -= nums[i - k + 1];
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {-1};
    s.findMaxAverage(nums, 1);
}