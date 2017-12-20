#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
// leetcode的答案
// https://discuss.leetcode.com/topic/5999/bucket-sort-java-solution-with-explanation-o-n-time-and-space
//利用抽屉原理
class Solution {
  public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;
        int m = nums.size();
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        double len = double(maxNum - minNum) / (m - 1);
        if (len == 0)
            return 0;
        vector<int> maxInBuckets(m, INT_MIN);
        vector<int> minInBuckets(m, INT_MAX);
        for (int i = 0; i < m; i++) {
            int index = (nums[i] - minNum) / len;
            maxInBuckets[index] = max(maxInBuckets[index], nums[i]);
            minInBuckets[index] = min(minInBuckets[index], nums[i]);
        }
        int gap = 0, prev = maxInBuckets[0];
        for (int i = 1; i < m; i++) {
            if (minInBuckets[i] != INT_MAX) {
                gap = max(gap, minInBuckets[i] - prev);
                prev = maxInBuckets[i];
            }
        }
        return gap;
    }
};

class Solution_0 {
  public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;
        int m = nums.size();
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        if (minNum == maxNum)
            return 0;
        int len = ceil(double(maxNum - minNum) / (nums.size() - 1));
        int bucketNum = ceil(double(maxNum - minNum) / len) + 1;
        vector<int> maxInBuckets(bucketNum, INT_MIN);
        vector<int> minInBuckets(bucketNum, INT_MAX);
        for (int i = 0; i < m; i++) {
            int index = (nums[i] - minNum) / len;
            maxInBuckets[index] = max(maxInBuckets[index], nums[i]);
            minInBuckets[index] = min(minInBuckets[index], nums[i]);
        }
        int gap = 0, prev = maxInBuckets[0];
        for (int i = 1; i < bucketNum; i++) {
            if (minInBuckets[i] != INT_MAX) {
                gap = max(gap, minInBuckets[i] - prev);
                prev = maxInBuckets[i];
            }
        }
        return gap;
    }
};