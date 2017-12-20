#include <cmath>
#include <climit>
using namespace std;
//不符合要求的解法
class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (n == 0)
            return false;
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1 ? true : false;
    }
};
// leetcode的答案，简直就是跪着唱字符
// https://discuss.leetcode.com/topic/36150/1-line-java-solution-without-loop-recursion
class Solution_0 {
  public:
    bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }
};

// leetcode的答案，简直就是跪着唱字符
// https://discuss.leetcode.com/topic/43385/c-solution-no-loop-recursion/2
class Solution_1 {
  public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        int t = pow(3, (int)(log(INT_MAX) / log(3)));
        return (t % n == 0);
    }
    /*
    int maxPow3 = (int) Math.pow(3, (int)(Math.log(Integer.MAX_VALUE) /
    Math.log(3)));

    public boolean isPowerOfThree(int n) {
        return (n > 0) && (maxPow3 % n == 0);
    }
    */
};