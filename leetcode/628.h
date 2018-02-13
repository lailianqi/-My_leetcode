#include <algorithm>
#include <vector>
using namespace std;

//最简单的写法 但是时间效率是O(logn*n)
class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[m - 1],
                   nums[m - 1] * nums[m - 2] * nums[m - 3]);
    }
};

// 另外一种写法 时间是O(n) 但是太长 并且不简洁
// https://leetcode.com/problems/maximum-product-of-three-numbers/discuss/104729/Java-O(1)-space-O(n)-time-solution-beat-100