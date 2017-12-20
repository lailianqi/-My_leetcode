#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//效率极低(n2)
class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= s) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
//自己写的 代码的结构不是非常的清晰 也是two pointer的解法
class Solution_0 {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int sum = 0, res = INT_MAX;
        for (int i = 0, j = 0; i < nums.size();) {
            if (sum < s && j < nums.size()) {
                sum += nums[j];
                j++;
            } else {
                if (sum >= s) {
                    res = min(res, j - i);
                }
                sum -= nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
//自己基于leetcode的解法的修改版 two pointer的解法
// https://discuss.leetcode.com/topic/18583/accepted-clean-java-o-n-solution-two-pointers
class Solution_1 {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int sum = 0, res = INT_MAX, i = 0, j = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= s) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
//二分查找的写法
// https://discuss.leetcode.com/topic/26814/o-n-o-nlogn-solutions-both-o-1-space/2
void test() {
    Solution_0 s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    s.minSubArrayLen(7, nums);
}