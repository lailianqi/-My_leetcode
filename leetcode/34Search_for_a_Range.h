#include <algorithm>
#include <iostream>
#include <vector>
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

// 第二遍刷的时候自己增加的解法 LeetCode存在类似方法的题解
// https://leetcode.com/problems/search-for-a-range/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)
// https://leetcode.com/problems/search-for-a-range/discuss/14701/A-very-simple-Java-solution-with-only-one-binary-search-algorithm
// 第三个题解来自sp大神
// https://leetcode.com/problems/search-for-a-range/discuss/14707/9-11-lines-O(log-n)
class Solution_1 {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) {
            return {-1, -1};
        }
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        return {it - nums.begin(), it2 - nums.begin() - 1};
    }
};
// sp大神的另外的一种解法
// https://leetcode.com/problems/search-for-a-range/discuss/14707/9-11-lines-O(log-n)
class Solution_2 {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        if (bounds.first == bounds.second)
            return {-1, -1};
        return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
    }
};

void test() {
    Solution s;
    vector<int> v = {-1, -1, 0, 0, 0, 2, 2, 3};
    cout << s.lower_bound(v, 1);
}

// 自己的lower_bound
int my_self_lower_bound(vector<int> &nums, int target) {
    auto first = nums.begin(), last = nums.end();
    while (first < last) {
        auto mid = first + ((last - first) >> 1);
        if (*mid < target) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first - nums.begin();
}