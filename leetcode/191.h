#include <stdint.h>
//自己的写法
class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            if (n & 1) {
                res++;
            }
        }
        return res;
    }
};

// leetcode上的其他的解法
// https://discuss.leetcode.com/topic/9915/short-code-of-c-o-m-by-time-m-is-the-count-of-1-s-and-another-several-method-of-o-1-time
class Solution_0 {
  public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};