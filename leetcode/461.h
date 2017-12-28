//这道题比较简单 自己的第一种方案 一次性ac
// LeetCode上同样想法的答案
// https://discuss.leetcode.com/topic/72093/java-1-line-solution-d
// https://discuss.leetcode.com/topic/72089/java-3-line-solution
class Solution {
  public:
    int hammingDistance(int x, int y) {
        int num = x ^ y, res = 0;
        for (int i = 0; i < 32; i++) {
            res += (num & 1);
            num >>= 1;
        }
        return res;
    }
};
// leetcode上另外一种思路的答案
// https://discuss.leetcode.com/topic/72236/my-c-solution-using-bit-manipulation/6
class Solution_0 {
  public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};