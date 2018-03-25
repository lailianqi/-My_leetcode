#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法  成功ac 用的空间换时间的方法
class Solution {
  public:
    int dominantIndex(vector<int> &nums) {
        int m = nums.size(), largestOne = -1, largestSecond = -1;
        vector<int> buckets(101, -1);
        for (int i = 0; i < m; i++) {
            buckets[nums[i]] = i;
        }
        for (int i = 100; i >= 0; i--) {
            if (buckets[i] != -1) {
                if (largestSecond == -1 && largestOne != -1) {
                    largestSecond = buckets[i];
                    break;
                }
                if (largestOne == -1) {
                    largestOne = buckets[i];
                }
            }
        }
        return largestSecond != -1 && nums[largestOne] < nums[largestSecond] * 2
                   ? -1
                   : largestOne;

        // 注释部分的解法是错的 因为数组并不是有序的
        // int largestOne = 0, largestSecond = -1, m = nums.size();
        // for (int i = 0; i < m; i++) {
        //     if (nums[i] > nums[largestOne]) {
        //         largestSecond = largestOne;
        //         largestOne = i;
        //     }
        // }
        // return largestSecond != -1 && nums[largestOne] < 2 *
        // nums[largestSecond]
        //            ? -1
        //            : largestOne;
    }
};

// leetcode的解法 感觉一般
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/discuss/119387/C++JavaPython-Concise-One-Pass-Solution-with-Explanation
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/discuss/112886/Java-One-pass-solution-o(n)-complexity
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/discuss/112880/My-C++-Solution

// python的解法 感觉更短
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/solution/