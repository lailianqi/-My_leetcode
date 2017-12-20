#include <map>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
//自己的写法，效率低下
class Solution {
  public:
    bool isHappy(int n) {
        set<int> record;
        while (!record.count(n)) {
            record.insert(n);
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            if (sum == 1) {
                return true;
            }
            cout << sum << endl;
            n = sum;
        }
        return false;
    }
};
// leetCode的写法
// https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
/*
I see the majority of those posts use hashset to record values. Actually, we can
simply adapt the Floyd Cycle detection algorithm. I believe that many people
have seen this in the Linked List Cycle detection problem. The following is my
code:
*/

class Solution_0 {
  public:
    bool isHappy(int n) {
        int walker = n, runner = n;
        do {
            walker = digitSquareSum(walker);
            runner = digitSquareSum(runner);
            runner = digitSquareSum(runner);
        } while (walker != runner);
        return walker == 1 ? true : false;
    }
    int digitSquareSum(int n) {
        int sum = 0;
        while (n) {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
};
void test() {
    Solution s;
    s.isHappy(2);
}