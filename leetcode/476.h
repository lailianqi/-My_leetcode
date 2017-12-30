#include <cmath>
//自己的第一种解法 成功ac
class Solution {
  public:
    int findComplement(int num) {
        int highBit = 0;
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                highBit = i + 1;
            }
        }
        return num ^ ((1 << highBit) - 1); // pow(2,highBit) -1
    }
};

// LeetCode的解法与上面的解法相似
// https://discuss.leetcode.com/topic/74642/java-1-line-bit-manipulation-solution/2?page=1
// https://discuss.leetcode.com/topic/74642/java-1-line-bit-manipulation-solution/15?page=1

//...................................
//第三种写法
class Solution_0 {
  public:
    int findComplement(int num) {
        int mask = 1;
        while (mask < num) {
            mask = (mask << 1) | 1;
        }
        return num ^ mask;
    }
};
//...................................

// leetcode上面算作第四种的写法
// https://discuss.leetcode.com/topic/74627/3-line-c?page=1