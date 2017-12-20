//自己无法按照题目要求写出来
// https://discuss.leetcode.com/topic/21498/accepted-c-o-1-time-o-1-space-1-line-solution-with-detail-explanations
/*
For base b (decimal case b = 10), the digit root of an integer is:
dr(n) = 0 if n == 0
dr(n) = (b-1) if n != 0 and n % (b-1) == 0
dr(n) = n mod (b-1) if n % (b-1) != 0
or
dr(n) = 1 + (n - 1) % 9
*/

// https://discuss.leetcode.com/topic/23279/two-lines-c-code-with-explanation
class Solution {
  public:
    int addDigits(int num) { return 1 + (num - 1) % 9; }
};