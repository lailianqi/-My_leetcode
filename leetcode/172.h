// leetcode的答案，自己没有想出来
// https://discuss.leetcode.com/topic/6513/simple-c-c-solution-with-detailed-explaination
class Solution {
  public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n >= 5) { //用除避免溢出
            n /= 5;
            ans += n;
        }
        return ans;
    }
};