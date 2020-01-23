#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/14597/solution-explained/2
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained
class Solution_0 {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        k = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int q = partition(nums, left, right);
            if (q == k) {
                return nums[q];
            } else if (q < k) {
                left = q + 1;
            } else {
                right = q - 1;
            }
        }
        return nums[k];
    }
    int partition(vector<int> &a, int left, int right) {
        int i = left, j = right + 1;
        int x = a[left];
        while (true) {
            while (a[++i] < x && i < right)
                ;
            while (a[--j] > x)
                ;
            if (i >= j) {
                break;
            }
            swap(a[i], a[j]);
        }
        swap(a[left], a[j]);
        return j;
    }
};

class Solution_1 {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        k = nums.size() - k;
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    int findKthLargest(vector<int> &nums, int left, int right, int k) {
        int q = partition(nums, left, right);
        if (q == k) {
            return nums[k];
        } else if (q < k) {
            return findKthLargest(nums, q + 1, right, k);
        } else {
            return findKthLargest(nums, left, q - 1, k);
        }
    }
    int partition(vector<int> &a, int left, int right) {
        int i = left, j = right + 1;
        int x = a[left];
        while (true) {
            while (a[++i] < x && i < right)
                ;
            while (a[--j] > x)
                ;
            if (i >= j) {
                break;
            }
            swap(a[i], a[j]);
        }
        swap(a[left], a[j]);
        return j;
    }
};

// 二刷-----------------------------
class Solution {
  public:
    int partion(vector<int> &nums, int left, int right) {
        int i = left, j = right + 1;
        int pivot = nums[left];
        while (i < j) {
            while (i < right && nums[++i] < pivot);
            while (j > left && nums[--j] > pivot);
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
    int findKthLargest(vector<int> &nums, int k) {
        int m = nums.size();
        k = m - k;
        return helper(nums, 0, m - 1, k);
    }
    int helper(vector<int> &nums, int left, int right, int k) {
        int pos = partion(nums, left, right);
        if (pos == k) {
            return nums[pos];
        }
        if (pos < k) {
            return helper(nums, pos + 1, right, k);
        }
        return helper(nums, left, pos - 1, k);
    }
};
// 另外的一种parition的写法
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60306/Python-different-solutions-with-comments-(bubble-sort-selection-sort-heap-sort-and-quick-sort).
class Solution_1 {
  public:
    int partion(vector<int> &nums, int left, int right) {
        int pivot = nums[right], i = left;
        while (left < right) {
            if (nums[left] < pivot) {
                swap(nums[left], nums[i]);
                i++;
            }
            left++;
        }
        swap(nums[i], nums[right]);
        return i;
    }
    int findKthLargest(vector<int> &nums, int k) {
        int m = nums.size();
        k = m - k;
        return helper(nums, 0, m - 1, k);
    }
    int helper(vector<int> &nums, int left, int right, int k) {
        int pos = partion(nums, left, right);
        if (pos == k) {
            return nums[pos];
        }
        if (pos < k) {
            return helper(nums, pos + 1, right, k);
        }
        return helper(nums, left, pos - 1, k);
    }
};