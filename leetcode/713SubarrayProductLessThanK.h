#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 知道要用滑动窗口的解法 但是没写出来 直接看的LeetCode的答案
// https://leetcode.com/problems/subarray-product-less-than-k/discuss/108830/C++-concise-solution-O(n)
// https://leetcode.com/problems/subarray-product-less-than-k/discuss/108861/JavaC++-Clean-Code-with-Explanation
class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int left = 0, product = 1, m = nums.size(), res = 0;
        for (int i = 0; i < m; i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            res += i - left + 1;
        }
        return res;
    }
};