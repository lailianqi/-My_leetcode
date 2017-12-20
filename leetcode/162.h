#include <vector>
using namespace std;
//方法一般
class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int m = nums.size();
        if (m == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        if (nums[m - 1] > nums[m - 2])
            return m - 1;
    }
};

// leetCode的方法
// Sequential Search:
//因为一开始就是递增序列，第一个不递增的前一个就是peek
// https://discuss.leetcode.com/topic/5724/find-the-maximum-by-binary-search-recursion-and-iteration/2
class Solution_0 {
  public:
    int findPeakElement(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return i - 1;
            }
        }
        return nums.size() - 1;
    }
};

// https://discuss.leetcode.com/topic/29329/java-solution-and-explanation-using-invariants/8
// leetcode的方法
// 二分查找
class Solution_1 {
  public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};