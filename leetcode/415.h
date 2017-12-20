#include <string>
#include <algorithm>
using namespace std;
//自己的解法 一次性ac 可惜写的太长了
class Solution {
  public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int carry = 0;
        for (int i = 0, j = 0; i < num1.size() || j < num2.size(); i++, j++) {
            int temp = (num1[i] - '0') +
                       (j < num2.size() ? (num2[j] - '0') : 0) + carry;
            carry = 0;
            if (temp >= 10) {
                carry = temp / 10;
                temp = temp % 10;
            }
            res.push_back('0' + temp);
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//自己对上面方法的改进版
class Solution_0 {
  public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int carry = 0;
        for (int i = 0, j = 0; i < num1.size() || j < num2.size(); i++, j++) {
            int temp = (i < num1.size() ? (num1[i] - '0') : 0) +
                       (j < num2.size() ? (num2[j] - '0') : 0) + carry;
            carry = temp / 10;
            temp = temp % 10;
            res.push_back('0' + temp);
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//自己又把上面的改进了
// leetcode上面的方法和下面的方法思路差不多
// https://discuss.leetcode.com/topic/62310/straightforward-java-8-main-lines-25ms
class Solution_1 {
  public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res;
        int carry = 0;
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            int temp = (i < num1.size() ? (num1[i] - '0') : 0) +
                       (j < num2.size() ? (num2[j] - '0') : 0) + carry;
            carry = temp / 10;
            res.push_back('0' + temp % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
void test() {
    string num1 = "9";
    string num2 = "98";
    Solution s;
    s.addStrings(num1, num2);
}