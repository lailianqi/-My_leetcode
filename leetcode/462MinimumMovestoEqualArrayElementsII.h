#include <algorithm>
#include <vector>
using namespace std;
// 没有深入的思考 直接看的答案
// https://discuss.leetcode.com/topic/68736/java-just-like-meeting-point-problem
class Solution {
  public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, res = 0;
        while (i < j) {
            res += nums[j--] - nums[i++];
        }
        return res;
    }
};

//下面的答案是上面答案的容易理解的版本
// sp大神的解法
// https://discuss.leetcode.com/topic/68946/2-lines-python-2-ways
class Solution_0 {
    int minMoves2(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int res = 0, mid = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            res += i > mid ? nums[i] - nums[mid] : nums[mid] - nums[i];
        }
        return res;
    }
};