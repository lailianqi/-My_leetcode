#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
// LeetCode上面类似的答案
// https://leetcode.com/problems/valid-palindrome-ii/discuss/107716/Java-O(n)-Time-O(1)-Space?page=1
// https://leetcode.com/problems/valid-palindrome-ii/discuss/107717/C++Java-Clean-Code-2-liner-Generic-for-%22you-may-delete-at-most-N-character%22

class Solution {
  public:
    bool validPalindrome(string s) {
        int m = s.size();
        for (int i = 0, j = m - 1; i < s.size(); i++, j--) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
    bool isPalindrome(string s, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};