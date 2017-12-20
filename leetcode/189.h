#include <vector>
#include <algorithm>
using namespace std;
//自己的解决方案
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int m = nums.size();
        k = k % m;
        reverse(nums.begin(), nums.begin() + m - k);
        reverse(nums.begin() + m - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// leetCode的另一种节法
// https://discuss.leetcode.com/topic/9801/summary-of-c-solutions/2
class Solution_0 {
  public:
    void rotate(int nums[], int n, int k) {
        for (; k = k % n; n -= k, nums += k) {
            // Swap the last k elements with the first k elements.
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements
            // to the right by k steps.
            for (int i = 0; i < k; i++) {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};