#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        vector<char> answer;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                answer.push_back(tolower(s[i]));
            }
            if (s[i] >= '0' && s[i] <= '9') {
                answer.push_back(s[i]);
            }
        }
        return judgePalindromic(answer);
    }
    bool judgePalindromic(vector<char> s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

// Leetcode的写法
class Solution_0 {
  public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j;
             i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j)
                i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j)
                j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j]))
                return false; // Exit and return error if not match
        }
        return true;
    }
};

// void test() {
//     Solution s;
//     s.isPalindrome("0P");
// }
// ---------------------------二刷
class Solution_1 {
  public:
    bool isPalindrome(string s) {
        int m = s.size();
        int left = 0, right = m - 1;
        while (left < right) {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }
            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};