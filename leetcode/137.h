#include <vector>
using namespace std;
//网上的解法
// http://www.cnblogs.com/grandyang/p/4263927.html
/*
对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，将所有这些1清零，剩下的就是最终的数。
用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的
1）的数位。用twos记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的
2）的数位。当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。即用二进制模拟三进制计算。最终ones记录的是最终结果。
*/
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                sum += (nums[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};

class Solution_1 {
  public:
    int singleNumber(vector<int> &nums) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < nums.size(); i++) {
            twos |= (ones & nums[i]);
            ones ^= nums[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};
//最容易理解的方案
// https://discuss.leetcode.com/topic/2926/accepted-code-with-proper-explaination-does-anyone-have-a-better-idea/2
class Solution_2 {
  public:
    int singleNumber(vector<int> &nums) {
        int ones = 0, twos = 0;
        int common_bit_mask;
        for (int i = 0; i < nums.size(); i++) {
            twos = twos | (ones & nums[i]);
            ones = ones ^ nums[i];
            common_bit_mask = ~(ones & twos);
            ones &= common_bit_mask;
            twos &= common_bit_mask;
        }
        return ones;
    }
};
//最牛逼的解法
// https://discuss.leetcode.com/topic/2031/challenge-me-thx/2?page=1
class Solution_3 {
  public:
    int singleNumber(vector<int> &nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};