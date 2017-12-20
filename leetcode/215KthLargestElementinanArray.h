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