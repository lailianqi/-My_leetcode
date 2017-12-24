#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

//直接套用格式  具体解释看下面的链接
// https://discuss.leetcode.com/topic/66737/it-is-a-math-question?page=1
// https://discuss.leetcode.com/topic/66557/java-o-n-solution-short/2?page=1
// https://discuss.leetcode.com/topic/66562/simple-one-liners
//一行代码是自己写出来的  想不到sp大神已经发过贴了
class Solution {
  public:
    int minMoves(vector<int> &nums) {
        return accumulate(nums.begin(), nums.end(), 0) -
               (int)(nums.size()) * (*min_element(nums.begin(), nums.end()));
    }
};