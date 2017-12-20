#include <cmath>
//虽然简单 但是没有想到点子上 所以第一次没有做出来
// leetcode的答案
// https://discuss.leetcode.com/topic/59314/java-solution
class Solution {
  public:
    int findNthDigit(int n) {
        int start = 1, len = 1;
        long counter = 9;
        while (n > counter * len) {
            n = n - counter * len;
            len++;
            counter = counter * 10;
            start = start * 10;
        }
        start = start + (n - 1) / len;
        string res = to_string(start);
        return res[(n - 1) % len] - '0';
    }
};

void test() {
    Solution s;
    s.findNthDigit(11);
}