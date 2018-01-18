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

// 更加短的一个方法 来自leetcode的答案
// https://discuss.leetcode.com/topic/80892/concise-c-solution-use-set-instead-of-map
class Solution_0 {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod))
                return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};