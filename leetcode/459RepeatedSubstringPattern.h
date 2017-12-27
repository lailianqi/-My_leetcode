#include <string>
using namespace std;
//自己的第一种方案 一次性ac 但是程序的效率太低
// leetcode上面相同思想的答案
// https://discuss.leetcode.com/topic/67992/java-simple-solution-with-explanation
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        for (int step = 1; step <= m / 2; step++) {
            for (int k = 0; k < m; k += step) {
                string temp = s.substr(0, step);
                if (temp != s.substr(k, step)) {
                    break;
                }
                if (k + step == m) {
                    return true;
                }
            }
        }
        return false;
    }
};
//基于leetcode答案 上面的稍微的改进版
// https://discuss.leetcode.com/topic/67992/java-simple-solution-with-explanation
class Solution_0 {
  public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        for (int i = m / 2; i >= 1; i--) {
            if (m % i == 0) {
                int batchNum = m / i;
                string batchString = s.substr(0, i), temp;
                for (int j = 0; j < batchNum; j++) {
                    temp += batchString;
                }
                if (temp == s) {
                    return true;
                }
            }
        }
        return false;
    }
};

//最牛逼的解法
// https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination/6
// https://discuss.leetcode.com/topic/79495/my-one-line-c-solution
class Solution_1 {
  public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
    }
};
void test() {
    Solution s;
    string str = "abab";
    s.repeatedSubstringPattern(str);
}