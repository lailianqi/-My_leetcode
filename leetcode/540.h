#include <vector>
using namespace std;
//第一种方案 成功ac 这道题太简单了 速度是O(n) 但是题目要求速度要是O(logn)
class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
// sp大神的答案 来自leetcode 写的太好了
// https://discuss.leetcode.com/topic/83310/short-compare-nums-i-with-nums-i-1
class Solution_0 {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

//下面的这种二分查找也还行 来自leetcode的答案
// https://discuss.leetcode.com/topic/82332/java-binary-search-o-log-n-shorter-than-others
class Solution_1 {
    int singleNonDuplicate(vector<int> &nums) {
        // binary search
        int n = nums.size(), lo = 0, hi = n / 2;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (nums[2 * m] != nums[2 * m + 1])
                hi = m;
            else
                lo = m + 1;
        }
        return nums[2 * lo];
    }
};