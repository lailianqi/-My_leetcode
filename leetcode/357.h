#include <cmath>
#include <vector>
using namespace std;
// 一开始就知道可以用dp做，但是没有想出来。
// leetcode的答案
// https://discuss.leetcode.com/topic/47983/java-dp-o-1-solution
class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int res = 10, uniqueDigits = 9, availableNumber = 9;
        while (--n > 0 && availableNumber > 0) {
            uniqueDigits = uniqueDigits * (availableNumber--);
            res += uniqueDigits;
        }
        return res;
    }
};