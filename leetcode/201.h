//这个方案超时
class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        for (int i = m; i <= n; i++) {
            res &= i;
        }
        return res;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/12133/bit-operation-solution-java?page=1
class Solution_0 {
  public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 1;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            res <<= 1;
        }
        return m * res;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/12133/bit-operation-solution-java/25?page=2
class Solution_1 {
  public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0; // i means we have how many bits are 0 on the right
        while (m != n) {
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m << i;
    }
};

// leetcode的答案
// https://discuss.leetcode.com/topic/20176/2-line-solution-with-detailed-explanation
class Solution_2 {
  public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n)
            n = n & (n - 1);
        return n;
    }
};

// https://discuss.leetcode.com/topic/13508/one-line-c-solution
class Solution_3 {
  public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};