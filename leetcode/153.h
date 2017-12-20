#include <vector>
using namespace std;
// leetcode的答案
// https://discuss.leetcode.com/topic/4100/compact-and-clean-c-solution
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            int mid = (start + end) / 2;
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};

// https://discuss.leetcode.com/topic/14768/4ms-simple-c-code-with-explanation/15
//
class Solution_0 {
  public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] > nums[right]) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};