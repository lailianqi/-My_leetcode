#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//参考了答案
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

//参考了答案
class Solution_0 {
  public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 1;
        }
        int k = partition(nums) + 1;
        int temp = 0;
        int first_missing_Index = k;
        for (int i = 0; i < k; i++) {
            temp = abs(nums[i]);
            if (temp <= k)
                nums[temp - 1] =
                    (nums[temp - 1] < 0) ? nums[temp - 1] : -nums[temp - 1];
        }
        for (int i = 0; i < k; i++) {
            if (nums[i] > 0) {
                first_missing_Index = i;
                break;
            }
        }
        return first_missing_Index + 1;
    }
    int partition(vector<int> &nums) {
        int n = nums.size();
        int q = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                swap(nums[i], nums[++q]);
            }
        }
        return q;
    }
};