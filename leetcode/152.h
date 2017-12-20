#include <vector>
using namespace std;
//自己的写法，直接用动态规划，并不想节约空间
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int m = nums.size();
        vector<int> maxDp(m, 0);
        vector<int> minDp(m, 0);
        int maxNum = nums[0];
        maxDp[0] = minDp[0] = nums[0];
        for (int i = 1; i < m; i++) {
            maxDp[i] = max(max(nums[i], maxDp[i - 1] * nums[i]),
                           minDp[i - 1] * nums[i]);
            maxNum = max(maxNum, maxDp[i]);
            minDp[i] = min(min(nums[i], maxDp[i - 1] * nums[i]),
                           minDp[i - 1] * nums[i]);
        }
        return maxNum;
    }
};

//leetcode的解法
/*
public int maxProduct(int[] nums) {
        int max = nums[0], maxToHere = nums[0], minToHere = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int temp = maxToHere;
            maxToHere = Math.max(Math.max(minToHere * nums[i], maxToHere * nums[i]), nums[i]);
            minToHere = Math.min(Math.min(minToHere * nums[i], temp * nums[i]), nums[i]);
            max = Math.max(max, maxToHere);
        }
        return max;
   }
*/