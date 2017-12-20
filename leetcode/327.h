#include <algorithm>
#include <vector>
using namespace std;
//首先是肯定超时的解法
//自己的第一反应
class Solution {
  public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int m = nums.size(), result = 0;
        vector<long> value(m + 1, 0);
        for (int i = 1; i < value.size(); i++) {
            value[i] = value[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                long temp = getSum(value, j, i);
                if (temp >= lower && temp <= upper) {
                    result++;
                }
            }
        }
        return result;
    }
    long getSum(vector<long> &value, int j, int i) {
        return value[j + 1] - value[i];
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/33738/share-my-solution/2
// https://discuss.leetcode.com/topic/45522/c-merge-sort-solution-very-short
class Solution_0 {
  public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int m = nums.size();
        vector<long> value(m + 1, 0);
        for (int i = 1; i < value.size(); i++) {
            value[i] = value[i - 1] + nums[i - 1];
        }
        return mergeSort(value, lower, upper, 0, value.size());
    }
    int mergeSort(vector<long> &value, int lower, int upper, int left,
                  int right) {
        int result = 0;
        if (left + 1 >= right) {
            return 0;
        }
        int middle = left + ((right - left) >> 1);
        result += mergeSort(value, lower, upper, left, middle) +
                  mergeSort(value, lower, upper, middle, right);
        for (int i = left, m = middle, n = middle; i < middle; i++) {
            while (m < right && value[m] - value[i] < lower)
                m++;
            while (n < right && value[n] - value[i] <= upper)
                n++;
            result += n - m;
        }
        inplace_merge(value.begin() + left, value.begin() + middle,
                      value.begin() + right);
        return result;
    }
};