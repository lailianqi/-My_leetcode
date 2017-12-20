#include <string>
#include <cstdlib>
using namespace std;
//自己的答案，但是代码太长了
class Solution {
  public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() && j < version2.size()) {
            int num1 = 0, num2 = 0;
            while (i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + version2[j] - '0';
                j++;
            }
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            } else {
                if (i == version1.size() || j == version2.size()) {
                    break;
                }
                i++;
                j++;
            }
        }
        if (i == version1.size() && j == version2.size())
            return 0;
        if (i == version1.size()) {
            if (atof(version2.substr(j + 1).c_str()) != 0)
                return -1;
        }
        if (j == version2.size()) {
            if (atof(version1.substr(j + 1).c_str()) != 0)
                return 1;
        }
        return 0;
    }
    int integerPart(string s) {
        int num = 0;
        int end = s.find('.') != -1 ? s.find('.') : s.size();
        for (int i = 0; i < end; i++) {
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
    int decimalPart(string s) {
        if (s.find('.') == -1) {
            return 0;
        }
        int num = 0;
        for (int i = s.find('.') + 1; i < s.size(); i++) {
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
};

void test() {
    Solution s;
    string s1 = "1.0";
    string s2 = "1";
    s.compareVersion(s1, s2);
}
// java的解法，非常的简单
// https://discuss.leetcode.com/topic/6238/accepted-small-java-solution?page=1
//下面是c++的解法,基本上是我的解法的改进版
// https://discuss.leetcode.com/topic/11410/my-2ms-easy-solution-with-c-c
class Solution_0 {
  public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int num1 = 0, num2 = 0;
            while (i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + version2[j] - '0';
                j++;
            }
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};

// python的解法
// https://discuss.leetcode.com/topic/18543/2-4-lines-python-3-different-ways/2