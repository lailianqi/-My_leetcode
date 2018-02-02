#include <string>
#include <vector>
using namespace std;
// 自己的第一种写法  成功ac 这道题比较简单
// 自己的第一种解法和LeetCode投票数最多的答案基本上100%相似 amazing
// https://discuss.leetcode.com/topic/86483/easy-to-understand-simple-o-n-solution-with-explanation
// https://discuss.leetcode.com/topic/86473/o-n-very-easy-java-solution
class Solution {
  public:
    string optimalDivision(vector<int> &nums) {
        int m = nums.size();
        if (m == 1) {
            return to_string(nums[0]);
        }
        if (m == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};