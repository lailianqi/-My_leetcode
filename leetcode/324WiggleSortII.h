#include <algorithm>
#include <vector>
using namespace std;
//这题真的毫无思路
//大神的答案
// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing?page=1
class Solution {
  public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};

//不符合要求的网友的解法
// http://www.cnblogs.com/grandyang/p/5139057.html
// https://discuss.leetcode.com/topic/32882/short-simple-c
//原理解释
// https://discuss.leetcode.com/topic/32861/3-lines-python-with-explanation-proof/2
class Solution_0 {
  public:
    void wiggleSort(vector<int> &nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};