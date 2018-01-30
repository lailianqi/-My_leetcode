#include <algorithm>
using namespace std;
// 直接看的LeetCode的答案 写不出来 这道题确实比较难
// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination/16
// https://discuss.leetcode.com/topic/64462/c-python-0ms-o-log-n-2-time-o-1-space-super-easy-solution-with-detailed-explanations
// http://bookshadow.com/weblog/2016/10/24/leetcode-k-th-smallest-in-lexicographical-order/
class Solution {
  public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = calSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    int calSteps(long n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};