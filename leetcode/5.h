#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
class Solution {
    public:
      bool judgePalindromic(string s) {
            for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
                  if (s[i] != s[j]) {
                        return false;
                  }
            }
            return true;
      }
      bool judgePalindromic(char *a, int length) {
            for (int i = 0, j = length - 1; i < j; i++, j--) {
                  if (a[i] != a[j]) {
                        return false;
                  }
            }
            return true;
      }
      int aroundCenter(string s, int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                  left--;
                  right++;
            }
            return right - left - 1;
      }
      // Expand Around Center
      string longestPalindrome(string s) {
            int len = 0;
            int start = 0;
            for (int i = 0; i < s.length(); i++) {
                  int len1 = aroundCenter(s, i, i);
                  int len2 = aroundCenter(s, i, i + 1);
                  if (len < max(len1, len2)) {
                        len = max(len1, len2);
                        start = i - (len - 1) / 2;
                  }
            }
            return s.substr(start, len);
      }
      // Brute Force ********//
      bool judgePalindromic(string s, int left, int right) {
            for (int i = left, j = right; i < j; i++, j--) {
                  if (s[i] != s[j]) {
                        return false;
                  }
            }
            return true;
      }
      string longestPalindrome2(string s) {
            int length = 1;
            int start = 0;
            for (int i = 0; i < s.length(); i++) {
                  for (int j = i + 1; j < s.length(); j++) {
                        if (judgePalindromic(s, i, j) && (j - i + 1 > length)) {
                              start = i;
                              length = j - i + 1;
                        }
                  }
            }
            return s.substr(start, length);
      }
      //**********************//
      // Dynamic Programming
      string longestPalindrome3(string s) {
            bool **a = new bool *[s.length()];
            for (int i = 0; i < s.length(); i++) {
                  a[i] = new bool[s.length()];
            }
            int length = 1;
            int start = 0;
            for (int i = 0; i < s.length(); i++) {
                  for (int j = 0; j < s.length(); j++) {
                        a[i][j] = false;
                        // cout << a[i][j] << endl;
                  }
            }
            for (int i = 0; i < s.length(); i++) {
                  a[i][i] = true;
            }
            for (int i = 0; i < s.length() - 1; i++) {
                  if (s[i] == s[i + 1]) {
                        a[i][i + 1] = true;
                        if (length < 2) {
                              start = i;
                              length = 2;
                        }
                  }
            }

            // for (int i = 0; i < s.length(); i++) {
            //       for (int j = 0; j < s.length(); j++) {
            //             cout << a[i][j] << " ";
            //       }
            //       cout << endl;
            // }

            for (int r = 3; r <= s.length(); r++) {
                  for (int i = 0; i <= s.length() - r; i++) {
                        int j = i + r - 1;
                        if (a[i + 1][j - 1] && s[i] == s[j]) {
                              a[i][j] = true;
                              if (length < j - i + 1) {
                                    length = j - i + 1;
                                    start = i;
                              }
                        }
                  }
            }
            return s.substr(start, length);
      }
};

void test() {
      Solution s;
      cout << s.longestPalindrome3(string("cbbd")) << endl;
}
