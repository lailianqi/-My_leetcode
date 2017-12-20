#include <vector>
using namespace std;
/*
Example 1:
nums = [1, 3], n = 6
Return 1.
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3],
[2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
*/
// SP大神的答案 本质是Greedy算法
// leetcode的答案
// https://discuss.leetcode.com/topic/35494/solution-explanation
class Solution {
  public:
    int minPatches(vector<int> &nums, int n) {
        int result = 0;
        for (long miss = 1, add = 0, i = 0; miss <= n;) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                result++;
            }
        }
        return result;
    }
};