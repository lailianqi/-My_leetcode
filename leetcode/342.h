
//虽然ac了。但是代码非常的丑陋
class Solution {
  public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        int temp = num, result = 0;
        for (int i = 0; i < 32; i++) {
            if (i % 2 == 0) {
                if (temp & 1)
                    result++;
            } else {
                if (temp & 1)
                    return false;
            }
            temp = temp >> 1;
        }
        return result == 1;
    }
};
//自己对上面解法的改进版
class Solution_0 {
  public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        int temp = num, result = 0;
        for (int i = 0; i < 32; i++) {
            if (temp & 1) {
                if (i % 2 == 0) {
                    result++;
                } else {
                    return false;
                }
            }
            temp = temp >> 1;
        }
        return result == 1;
    }
};
// leetcode的解法
//非常的牛逼
// https://discuss.leetcode.com/topic/42860/java-1-line-cheating-for-the-purpose-of-not-using-loops
// https://discuss.leetcode.com/topic/42914/1-line-c-solution-without-confusing-bit-manipulations
class Solution_1 {
  public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
};