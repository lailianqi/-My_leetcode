#include <cmath>
//自己的第一种的写法  成功ac 但是运行效率不高
class Solution {
  public:
    int arrangeCoins(int n) {
        long long k = 1;
        while (pow(k, 2) + k <= 2 * (long)n) {
            k++;
        }
        return k - 1;
    }
};
//对自己解法的改进版 击败了99.51的答案
class Solution_0 {
  public:
    int arrangeCoins(int n) {
        int start = 1, end = n;
        while (start <= end) {
            int middle = start + ((end - start) >> 1);
            if ((pow(middle, 2) + middle) / 2 <= n) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        return start - 1;
    }
};

// leetcode的另外的一种方案
// https://discuss.leetcode.com/topic/65575/java-o-1-solution-math-problem
// https://discuss.leetcode.com/topic/65593/java-clean-code-with-explanations-and-running-time-2-solutions
class Solution_1 {
  public:
    int arrangeCoins(int n) { return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2); }
};
