#include <vector>
using namespace std;
//这题不知道公式是没法做的

/*
1. a^b % 1337 = (a%1337)^b % 1337
2. xy % 1337 = ((x%1337) * (y%1337)) % 1337
One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 %
k) % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
Implementation of this idea:

*/
// leetcode的答案
// https://discuss.leetcode.com/topic/50489/c-clean-and-short-solution?page=1
class Solution {
  public:
    int powMod(int a, int k) {
        a = a % 1337;
        int res = 1;
        for (int i = 0; i < k; i++) {
            res = (res * a) % base;
        }
        return res;
    }
    int superPow(int a, vector<int> &b) {
        if (b.empty()) {
            return 1;
        }
        int last_digit = b.back();
        b.pop_back();
        return powMod(superPow(a, b), 10) * powMod(a, last_digit) % base;
    }

  private:
    const int base = 1337;
};