#include <stdint.h>
// leetcode的答案
// https://discuss.leetcode.com/topic/9863/my-3ms-pure-c-solution/2
// https://discuss.leetcode.com/topic/9811/o-1-bit-operation-c-solution-8ms
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            res <<= 1;
            res |= n & 1;
        }
        return res;
    }
};
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1, ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            if (mask & n)
                ret |= 1;
            mask <<= 1;
        }
        return ret;
    }
};