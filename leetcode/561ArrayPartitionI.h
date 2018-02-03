#include <algorithm>
#include <vector>
using namespace std;
// 自己的第一种解法 成功ac 用的贪心的思想 比较简单
// leetcode上面的答案和我的想法以及做法一样一样
// LeetCode上面对理论的证明还是非常的精彩的
// https://discuss.leetcode.com/topic/87206/java-solution-sorting-and-rough-proof-of-algorithm
class Solution {
  public:
    int arrayPairSum(vector<int> &nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};

// 第二种方法来自LeetCode 时间复杂度是O(n) 用的堆排序 非常的巧妙 值得一看
// https://discuss.leetcode.com/topic/87483/c-code-o-n-beats-100
// https://discuss.leetcode.com/topic/87483/c-code-o-n-beats-100/5
class Solution_0 {
  public:
    int arrayPairSum(vector<int> &nums) {
        vector<int> buckets(20001);
        int sum = 0, divation = 10000;
        for (auto e : nums) {
            ++buckets[e + divation];
        }
        for (int i = 0, j = 1; i < buckets.size();) {
            if (buckets[i] > 0) {
                if (j) {
                    sum += i - divation;
                }
                j ^= 1;
                buckets[i]--;
            } else {
                i++;
            }
        }
        return sum;
    }
};