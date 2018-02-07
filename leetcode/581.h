#include <algorithm>
#include <vector>
using namespace std;
//自己的第一种方案 成功ac
class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        int m = nums.size();
        if (m <= 1) {
            return 0;
        }
        vector<int> maxArr(m, 0), minArr(m, 0);
        for (int i = 0; i < nums.size(); i++) {
            maxArr[i] = i == 0 ? nums[0] : max(maxArr[i - 1], nums[i]);
        }
        for (int i = m - 1; i >= 0; i--) {
            minArr[i] = i == m - 1 ? nums[m - 1] : min(minArr[i + 1], nums[i]);
        }
        int right = m - 1, left = 0;
        while (right > 0 && minArr[right] >= maxArr[right - 1]) {
            right--;
        }
        while (left < m - 1 && maxArr[left] <= minArr[left + 1]) {
            left++;
        }
        return right - left < 0 ? 0 : right - left + 1;
    }
};

// 来自LeetCode的答案 就是上面思想的简化版 写的非常的不错
// https://discuss.leetcode.com/topic/89282/java-o-n-time-o-1-space
// https://discuss.leetcode.com/topic/93391/ideas-behind-the-o-n-two-pass-and-one-pass-solutions/2
class Solution_0 {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        int m = nums.size(), left = -1, right = -2, minValue = nums[m - 1],
            maxValue = nums[0];
        for (int i = 1; i < m; i++) {
            maxValue = max(maxValue, nums[i]);
            minValue = min(minValue, nums[m - 1 - i]);
            if (nums[i] < maxValue) {
                right = i;
            }
            if (nums[m - i - 1] > minValue) {
                left = m - i - 1;
            }
        }
        return right - left + 1;
    }
    /*
    public int findUnsortedSubarray(int[] nums) {
        int i = 0, j = -1, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        

        for (int l = 0, r = nums.length - 1; r >= 0; l++, r--) {
            max = Math.max(max, nums[l]);
            if (nums[l] != max) j = l;
            


            min = Math.min(min, nums[r]);
            if (nums[r] != min) i = r;
        }
        return (j - i + 1);
    }
    */
};

// 还有一种方法 最简单 但是时间最长 naive solution 就是直接排序的方法
// https://discuss.leetcode.com/topic/89300/java-solution-sort