#include <vector>
#include <algorithm>
using namespace std;

//没有想出来
// leetcode的答案
// https://discuss.leetcode.com/topic/25382/sharing-explanation-of-the-solution
// https://discuss.leetcode.com/topic/21605/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations?page=1
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> rets(2, 0);
        for (int num : nums)
            rets[!(num & diff)] ^= num;
        return rets;
    }
};