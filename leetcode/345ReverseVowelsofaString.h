#include <string>
using namespace std;
//非常容易就AC了，自己的第一种方案
// leetcode 的答案，和我的方案的思路(two
// pointer solution)是一样的，但是没有我写的好
// https://discuss.leetcode.com/topic/43412/java-standard-two-pointer-solution
class Solution {
  public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j;) {
            while (i < j && !isVowels(s[i])) {
                i++;
            }
            while (i < j && !isVowels(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }
};
//上面的超级微小的改进版
class Solution_0 {
  public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j;) {
            while (i < j && !isVowels(s[i])) {
                i++;
            }
            while (i < j && !isVowels(s[j])) {
                j--;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }
};

// leetcode直接使用STL算法库
//和上面的解法的想法是一样的
// https://discuss.leetcode.com/topic/43452/super-clean-c-solution-using-find_first_of-and-find_last_of
class Solution_1 {
  public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
// leetcode的答案
// python大神的解法
// https://discuss.leetcode.com/topic/43463/1-2-lines-python-ruby