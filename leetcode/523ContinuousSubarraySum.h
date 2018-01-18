#include <vector>
#include <unordered_map>
using namespace std;
// 没想出来 直接看的leetcode的答案
// leetcode的答案的链接
// https://discuss.leetcode.com/topic/80793/java-o-n-time-o-k-space
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> dir;
        dir[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k) {
                sum %= k;
            }
            if (dir.count(sum)) {
                int prev = dir[sum];
                if (i - prev > 1) {
                    return true;
                }
            } else {
                dir[sum] = i;
            }
        }
        return false;
    }
};