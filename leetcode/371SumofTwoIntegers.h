//这题并没有写出来，看来对位运算还是缺乏足够的理解
// https://discuss.leetcode.com/topic/49771/java-simple-easy-understand-solution-with-explanation
// https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
class Solution {
  public:
    int getSum(int a, int b) {
        while (b) {
            int uncarry = a ^ b;
            int carry = (a & b) << 1;
            a = uncarry;
            b = carry;
        }
        return a;
    }

    // Iterative
    //对减法仍有疑问
    int getSubtract(int a, int b) {
        while (b != 0) {
            int borrow = (~a) & b;
            a = a ^ b;
            b = borrow << 1;
        }
        return a;
    }
};