#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
      bool judgePalindromic(string s) {
            for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
                  if (s[i] != s[j]) {
                        return false;
                  }
            }
            return true;
      }
      //自己的第一想法
      bool isPalindrome(int x) {
            string s = "";
            if (x < 0) { //负数不可能是回文数
                  return false;
            }
            if (x == 0) {
                  return true;
            }
            while (x) {
                  s += x % 10;
                  x /= 10;
            }
            return judgePalindromic(s);
      }
      //标准的答案
      bool isPalindrome1(int x) {
            if (x < 0 || (x != 0 && x % 10 == 0))
                  return false;
            int sum = 0;
            while (x > sum) {
                  sum = sum * 10 + x % 10;
                  x = x / 10;
            }
            return (x == sum || x == sum / 10);
      }
};

void test() {
      Solution s;
      if (s.isPalindrome(1354))
            cout << "yes" << endl;
      else {
            cout << "no" << endl;
      }
}
