#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
      string convert(string s, int numRows) {
            if (numRows <= 1)
                  return s;
            string *a = new string[s.length()];
            for (int i = 0; i < s.length(); i++) {
                  a[i] = "";
            }
            int row = 0;
            int delta = 1;
            for (int i = 0; i < s.length(); i++) {
                  a[row] += s[i];
                  row += delta;
                  if (row >= numRows) {
                        row -= 2;
                        delta = -1;
                  }
                  if (row < 0) {
                        row += 2;
                        delta = 1;
                  }
            }
            string result = "";
            for (int i = 0; i < s.length(); i++) {
                  result += a[i];
            }
            delete[] a;
            return result;
      }
};

void test() {
      Solution s;
      cout << s.convert("ABC", 1) << endl;
}