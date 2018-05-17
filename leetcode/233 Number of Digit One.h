//没有写出来 好题
// leetcode的答案
// https://discuss.leetcode.com/topic/18054/4-lines-o-log-n-c-java-python
class Solution {
  public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10) {
            res += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        }
        return res;
    }
};
//下面是更加易懂的版本,上面的修改版
class Solution_0 {
  public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int a = n / m, b = n % m;
            res += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return res;
    }
};