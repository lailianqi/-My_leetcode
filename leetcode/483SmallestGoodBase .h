#include <string>
#include <cmath>
using namespace std;
//直接看的leetcode答案 用的数学的方法
// https://discuss.leetcode.com/topic/76368/python-solution-with-detailed-mathematical-explanation-and-derivation/2
// https://discuss.leetcode.com/topic/76347/3ms-ac-c-long-long-int-binary-search/2
class Solution {
    typedef unsigned long long ull;

  public:
    string smallestGoodBase(string n) {
        ull num = (ull)stoll(n);
        int max_m = log(num) / log(2);
        for (int k = max_m; k >= 2; k--) {
            ull b = pow(num, 1.0 / k), sum = 1, cur = 1;
            for (int i = 1; i <= k; ++i)
                sum += (cur *= b);
            if (sum == num) {
                return to_string(b);
            }
        }
        return to_string(num - 1);
    }
};