#include <string>
#include <ctype>
using namespace std;
//自己的第一种写法 成功ac 但是代码太长
class Solution {
  public:
    bool detectCapitalUse(string word) {
        return isUpperWord(word) || islowerWord(word) || CapitalInFirst(word);
    }
    bool isUpperWord(string &word) {
        for (int i = 0; i < word.size(); i++) {
            if (!isupper(word[i])) {
                return false;
            }
        }
        return true;
    }
    bool islowerWord(string &word) {
        for (int i = 0; i < word.size(); i++) {
            if (!islower(word[i])) {
                return false;
            }
        }
        return true;
    }
    bool CapitalInFirst(string &word) {
        string s = word.substr(1);
        if (isupper(word[0]) && islowerWord(s)) {
            return true;
        }
        return false;
    }
};

// leetcode上面的答案  写的非常的不错 比上面解法牛逼多了
// https://discuss.leetcode.com/topic/79912/3-lines
class Solution {
  public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto element : word) {
            if (isupper(element)) {
                cnt++;
            }
        }
        return cnt == 0 || cnt == word.size() || (cnt == 1 && isupper(word[0]));
    }
};