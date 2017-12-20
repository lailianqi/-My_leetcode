#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
//自己的方法和leetcode的方法一样
// https://discuss.leetcode.com/topic/6214/my-1-lines-code-in-java-c-and-python
// https://discuss.leetcode.com/topic/6248/accepted-java-solution/2
// https://discuss.leetcode.com/topic/17223/short-0ms-c-solution
class Solution {
  public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            n--;
            s += 'A' + n % 26;
            n = n / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

void test() {
    string s = "sdggs";
    reverse(s.begin(), s.end());
    cout << s << endl;
}