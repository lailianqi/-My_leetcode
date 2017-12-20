#include <vector>
#include <string>
using namespace std;

/*
Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/
//自己的答案 速度0ms 不过感觉代码的结构还不够完美
class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        int begin = nums[0], counter = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 != nums[i - 1]) {
                counter == 0 ? res.push_back(to_string(begin))
                             : res.push_back(to_string(begin) + "->" +
                                             to_string(begin + counter));
                begin = nums[i];
                counter = 0;
            } else {
                counter++;
            }
        }
        counter == 0 ? res.push_back(to_string(begin))
                     : res.push_back(to_string(begin) + "->" +
                                     to_string(begin + counter));
        return res;
    }
};
// leetcode的好答案
// https://discuss.leetcode.com/topic/17151/accepted-java-solution-easy-to-understand/18
class Solution_0 {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
                i++;
            if (num != nums[i]) {
                res.push_back(to_string(num) + "->" + to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]));
            }
        }
        return res;
    }
};