#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    // 最简单的二分法方案
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> answer(2, -1);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                int start = mid, end = mid;
                while (start >= 0 && nums[start] == target) {
                    start--;
                }
                while (end <= nums.size() - 1 && nums[end] == target) {
                    end++;
                }
                answer[0] = start + 1;
                answer[1] = end - 1;
                return answer;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
    // find the first number that is greater than or equal to target.
    // could return A.length if target is greater than A[A.length-1].
    // actually this is the same as lower_bound in C++ STL.
    vector<int> searchRange1(vector<int> &nums, int target) {
        vector<int> answer(2, -1);
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return answer;
        }
        answer[0] = start;
        answer[1] = lower_bound(nums, target + 1) - 1;
        return answer;
    }
    int lower_bound(vector<int> &nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

void test() {
    Solution s;
    vector<int> v = {-1, -1, 0, 0, 0, 2, 2, 3};
    cout << s.lower_bound(v, 1);
}