#include <cmath>
#include <iostream>
using namespace std;
//超时的做法
class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        double sum = 1;
        int sign = abs(n) / n;
        n = abs(n);
        for (int i = 0; i < n; i++) {
            sum *= x;
        }
        return sign > 0 ? sum : 1 / sum;
    }
};

// https://leetcode.com/problems/powx-n/discuss/19546/Short-and-easy-to-understand-solution
// https://leetcode.com/problems/powx-n/discuss/19544/5-different-choices-when-talk-with-interviewers
class Solution_0 {
  public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        double t = myPow(x, n / 2);
        if (n % 2 == 0) {
            return t * t;
        } else {
            return n < 0 ? 1 / x * t * t : x * t * t;
        }
    }
};

// When n=Integer.MIN_VALUE, then n=-n will overflow.

class Solution_1 {
  public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1) {
            return x;
        }
        double t = myPow(x, n / 2);
        if (n % 2 == 0) {
            return t * t;
        } else {
            return n < 0 ? 1 / x * t * t : x * t * t;
        }
    }
};
