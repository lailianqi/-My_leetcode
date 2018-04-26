#include <climits>
#include <vector>
using namespace std;

// 下面都是第一遍刷的时候写的版本 太烂 不建议看
// 详细的版本参照python的题库
class Solution {
  public:
    //最简单的方法，效率最低
    int search(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    // 利用二分查找的解法 来自LeetCode
    // https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search
    int search1(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
    int search2(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        int num;
        while (left <= right) {
            mid = (left + right) / 2;
            // In the same side
            if ((nums[mid] < nums[0]) == (target < nums[0])) {
                num = nums[mid];
            } else {
                if (target < nums[0]) {
                    num = INT_MIN;
                } else {
                    num = INT_MAX;
                }
            }
            if (num < target)
                left = mid + 1;
            else if (num > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};