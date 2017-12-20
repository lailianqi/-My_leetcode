#include <string>
#include <algorithm>
using namespace std;
//好久没有看到这么简单的题目了
//第一种解法 直接调用STL库写的
class Solution {
  public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
//第二种方法 自己写的
//手动翻转 不调用任何的函数
// leetcode有相同的答案
// https://discuss.leetcode.com/topic/43298/simple-c-solution
class Solution_0 {
  public:
    string reverseString(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
};