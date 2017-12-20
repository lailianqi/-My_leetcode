#include <string>
#include <iostream>
using namespace std;
//自己的第一种写法，历经千辛万苦写出来的方案
class Solution {
  public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = 1; (min(i, j) + 2 * max(i, j)) <= num.size(); j++) {
                if (isVaild(num.substr(0, i)) && isVaild(num.substr(i, j))) {
                    long left = stol(num.substr(0, i));
                    long right = stol(num.substr(i, j));
                    if (helper(num.substr(i + j), left, right))
                        return true;
                }
            }
        }
        return false;
    }
    bool helper(string num, long left, long right) {
        for (int i = 1; i <= num.size(); i++) {
            if (!isVaild(num.substr(0, i))) {
                return false;
            }
            long temp = stol(num.substr(0, i));
            if (temp == (left + right)) {
                if (i == num.size() || helper(num.substr(i), right, temp)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isVaild(string s) {
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        return true;
    }
};
//参考leetcode写的答案
// https://discuss.leetcode.com/topic/29856/java-recursive-and-iterative-solutions?page=1
class Solution_0 {
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            if (!isVaild(num.substr(0, i)))
                return false;
            for (int j = 1; (min(i, j) + 2 * max(i, j)) <= num.size(); j++) {
                if (!isVaild(num.substr(i, j))) {
                    break;
                }
                long left = stol(num.substr(0, i));
                long right = stol(num.substr(i, j));
                if (helper(num.substr(i + j), left, right))
                    return true;
            }
        }
        return false;
    }
    bool helper(string num, long left, long right) {
        if (num.empty()) {
            return true;
        }
        long temp = left + right;
        string str = to_string(temp);
        return num.compare(0, str.size(), str) == 0 &&
               helper(num.substr(str.size()), right, temp);
    }
    bool isVaild(string s) {
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        return true;
    }
};

// Iterative的写法 leetcode上的答案
// https://discuss.leetcode.com/topic/29856/java-recursive-and-iterative-solutions?page=1
class Solution_1 {
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = 1; (min(i, j) + 2 * max(i, j)) <= num.size(); j++) {
                if (helper(num, i, j))
                    return true;
            }
        }
        return false;
    }
    bool helper(string num, int i, int j) {
        if (num[0] == '0' && i > 1)
            return false;
        if (num[i] == '0' && j > 1)
            return false;
        long left = stol(num.substr(0, i));
        long right = stol(num.substr(i, j));
        string sum;
        for (int start = i + j; start < num.length(); start += sum.length()) {
            long temp = left + right;
            left = right;
            right = temp;
            sum = to_string(right);
            if (num.compare(start, sum.size(), sum) != 0)
                return false;
        }
        return true;
    }
};

void test() {
    Solution s;
    s.isAdditiveNumber("198019823962");
}