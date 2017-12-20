#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <climits>
#include <map>
using namespace std;
//自己没有想出来，下面是leetcode的答案
// https://discuss.leetcode.com/topic/18453/c-using-set-less-10-lines-with-simple-explanation/24?page=2
// https://discuss.leetcode.com/topic/18453/c-using-set-less-10-lines-with-simple-explanation?page=1\
//时间复杂度O(n)
class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long long> window; //防止overflow
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                // keep the set contains nums i j at most k
                window.erase(nums[i - k - 1]);
            }
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long long)nums[i] - t);
            // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos - nums[i] <= t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
//第二种的解法
// https://discuss.leetcode.com/topic/15199/ac-o-n-solution-in-java-using-buckets-with-explanation?page=1
// https://discuss.leetcode.com/topic/15199/ac-o-n-solution-in-java-using-buckets-with-explanation/30?page=2
class Solution_0 {
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0)
            return false;
        map<long long, long long> directory;
        for (int i = 0; i < nums.size(); ++i) {
            long long remappedNum = (long long)nums[i] - INT_MIN;
            long long bucket = remappedNum / ((long long)t + 1);
            if ((directory.find(bucket) != directory.end()) ||
                (directory.find(bucket - 1) != directory.end() &&
                 abs(directory[bucket - 1] - nums[i]) <= t) ||
                (directory.find(bucket + 1) != directory.end() &&
                 abs(directory[bucket + 1] - nums[i]) <= t)) {
                return true;
            }
            if (directory.size() >= k) {
                long long lastBucket =
                    ((long long)nums[i - k] - INT_MIN) / ((long)t + 1);
                directory.erase(lastBucket);
            }
            directory[bucket] = nums[i];
        }
        return false;
    }
};