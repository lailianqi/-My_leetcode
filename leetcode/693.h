

class Solution {
  public:
    bool hasAlternatingBits(int n) {
        n ^= n >> 2;
        return !(n & (n - 1));
    }
};

// 更加寻常的做法
class Solution_0 {
  public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n >>= 1;
        while (n > 0) {
            if ((n & 1) == prev) {
                return false;
            }
            prev = n & 1;
            n >>= 1;
        }
        return true;
    }
};

//第二种解法 这种解法是最牛逼的 来自LeetCode的答案
// https://leetcode.com/problems/binary-number-with-alternating-bits/discuss/108427/Oneliners-(C++-Java-Ruby-Python)
class Solution_1 {
  public:
    bool hasAlternatingBits(int n) { return !((n ^= (n >> 1)) & (n + 1)); }
};