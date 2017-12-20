#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//自己的答案
class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);
        int m = a.length(), n = b.length();
        int temp = m - n;
        int sum = 0;
        string s = "";
        for (int i = m - 1; i >= 0; i--) {
            sum = sum + a[i] - '0' + (i - temp >= 0 ? b[i - temp] - '0' : 0);
            s = to_string(sum % 2) + s;
            sum = sum / 2;
        }
        if (sum != 0) {
            s = to_string(sum) + s;
        }
        return s;
    }
};

//基本上同一个思路的方案
class Solution_0 {
  public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};
class Solution_1 {
  public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;
        int m = a.length() - 1, n = b.length() - 1;
        while (m>=0 || n>=0 || carry) {
            carry += (m >= 0 ? a[m--] - '0' : 0) + (n >= 0 ? b[n--] - '0' : 0);
            s = char(carry % 2 + '0') + s;
            carry /= 2;
        }
        return s;
    }
};

void test() {
    Solution s;
    string s1 = "1010";
    string s2 = "1011";
    cout << s.addBinary(s1, s2);
}