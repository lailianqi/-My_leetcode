#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
// LeetCode上面相似的答案
// https://discuss.leetcode.com/topic/83019/java-10-liner-solution-simplest-so-far
// https://discuss.leetcode.com/topic/83019/java-10-liner-solution-simplest-so-far/4
// https://discuss.leetcode.com/topic/82629/c-clean-code/2
class Solution {
  public:
    int findMinDifference(vector<string> &timePoints) {
        int hour = 0, minutes = 0, res = INT_MAX;
        char buff;
        vector<int> nums;
        for (int i = 0; i < timePoints.size(); i++) {
            stringstream ss(timePoints[i]);
            ss >> hour >> buff >> minutes;
            nums.push_back(hour * 60 + minutes);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        res = min(res, nums[0] + 24 * 60 - nums[nums.size() - 1]);
        return res;
    }
};

// leetcode上的答案 运行效率比上面的高
// https://discuss.leetcode.com/topic/82573/verbose-java-solution-bucket