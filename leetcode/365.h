
//写不出来
// leetcode的解法
// https://discuss.leetcode.com/topic/49238/math-solution-java-solution/2
//纯数学的方法
class Solution {
  public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        if (x == z || y == z || x + y == z)
            return true;
        return z % gcd(x, y) == 0;
    }
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};