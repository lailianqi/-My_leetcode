#include <vector>
using namespace std;
/*
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3
+ 3 + 4).*/

//好久木有dp问题轻松搞定了 开心
//自己的第一种方法
//在leetcode发现了和我解法差不多的方法,但是没有我写的好
// https://discuss.leetcode.com/topic/42978/java-dp-solution/2
class Solution {
  public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};

//另外的一种解法的数学解释
// https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem/10?page=1
