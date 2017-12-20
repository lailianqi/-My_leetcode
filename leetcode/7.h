#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
    public:
      int reverse(int x) {
            int sum = 0;
            int recond = 0;
            while (x) {
                  recond = sum;
                  sum = sum * 10 + x % 10;
                  if ((sum - x % 10) / 10 != recond)
                        return 0;
                  x = x / 10;
            }
            return sum;
      }
      int reverse2(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

void test() {
      Solution s;
      cout << s.reverse2(0) << endl;
}