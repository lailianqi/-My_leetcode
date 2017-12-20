#include <vector>
using namespace std;
//自己写的答案
// Your runtime beats 25.95 % of cpp submissions.
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] >= nums[right] && left < right) {
            while (nums[left] == nums[left + 1] && left < right)
                left++;
            while (nums[right] == nums[right - 1] && left < right)
                right--;
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

// leetcode的答案
// https://discuss.leetcode.com/topic/54771/solution-in-c-well-explained/2
// https://discuss.leetcode.com/topic/6468/my-pretty-simple-code-to-solve-it
// https://discuss.leetcode.com/topic/25248/super-simple-and-clean-java-binary-search
class Solution_0 {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m + 1;
            else
                r--;
        }
        return nums[l];
    }
};