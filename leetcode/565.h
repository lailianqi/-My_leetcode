#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac    runtime beats 100.00 % of cpp submissions
// 这道的重点是要发现所有数形成的肯定是一个环 没有尾巴的环
// 因为所有的数都是不一样的
// LeetCode上面类似的答案 思想差不多
// https://discuss.leetcode.com/topic/90538/c-java-clean-code-o-n
class Solution {
  public:
    int arrayNesting(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int length = 0;
            for (int j = i; nums[j] != -1; length++) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
            }
            res = max(res, length);
        }
        return res;
    }
};

// python的写法
// https://discuss.leetcode.com/topic/90552/short-python