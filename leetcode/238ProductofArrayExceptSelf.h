#include <vector>
using namespace std;
//确实没有想到，而且返回的数组不算空间，所以一开始对题目存在误解
// https://discuss.leetcode.com/topic/18864/simple-java-solution-in-o-n-without-extra-space
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int m = nums.size();
        vector<int> res(m, 1);
        for (int i = 1; i < m; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int i = m - 1, right = 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right = right * nums[i];
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {0, 0};
    s.productExceptSelf(nums);
}