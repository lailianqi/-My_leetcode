#include <algorithm>
#include <vector>
using namespace std;
// 自己的第一种 方案 成功ac
// LeetCode的答案和我的一模一样
class Solution {
  public:
    int findLengthOfLCIS(vector<int> &nums) {
        int m = nums.size(), res = 0, counter = 0;
        for (int i = 0; i < m; i++) {
            if (i == 0 || nums[i] <= nums[i - 1]) {
                counter = 1;
            } else {
                counter++;
            }
            res = max(res, counter);
        }
        return res;
    }
};