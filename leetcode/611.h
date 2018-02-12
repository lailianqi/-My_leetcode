#include <algorithm>
#include <vector>
using namespace std;
// 自己的第一种方案 three pointer的方案 成功ac
// leetcode上面类似的答案
// https://discuss.leetcode.com/topic/92099/java-o-n-2-time-o-1-space
// https://discuss.leetcode.com/topic/92110/java-solution-3-pointers
class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size(), res = 0;
        for (int i = m - 1; i >= 0; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};