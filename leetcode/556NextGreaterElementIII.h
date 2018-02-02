#include <algorithm>
#include <string>
using namespace std;
// 排列组合的题 有点忘记了所以没有去写
// 典型的排列组合的题 可直接调用函数
// 来自LeetCode的答案 直接调用的函数
// https://discuss.leetcode.com/topic/85740/c-4-lines-next_permutation
class Solution {
  public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(digits.begin(), digits.end());
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

// 全排列不调用代码的实现 可以当做复习了
// https://discuss.leetcode.com/topic/85787/c-solution-with-explanation
// https://discuss.leetcode.com/topic/85787/c-solution-with-explanation/2
// https://discuss.leetcode.com/topic/86049/simple-java-solution-4ms-with-explanation/3

class Solution_0 {
  public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.length() == 1) {
            return -1;
        }
        int i = s.length() - 2;
        for (; i >= 0 && s[i] >= s[i + 1]; i--) {
        }
        if (i == -1) {
            return -1;
        }
        reverse(s.begin() + i + 1, s.end());
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        }
        long next = stol(s);
        return next == n || next > INT_MAX ? -1 : next;
    }
};