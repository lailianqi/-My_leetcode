#include <string>
using namespace std;

// You are here! Your runtime beats 4.47 % of cpp submissions.
//自己的答案
class Solution {
  public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0)
            return 0;
        int index = 0;
        int count = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ')
                index = i + 1;
        }
        for (int i = index; s[i] != ' ' && i < s.length(); i++)
            count++;
        return count;
    }
};

// You are here! Your runtime beats 0.71 % of cpp submissions.
//运行时间太差
class Solution_0 {
  public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0)
            return 0;
        int lastLength = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                lastLength++;
            else if (s[i] == ' ' && (i + 1 < s.length() && s[i + 1] != ' ')) {
                lastLength = 0;
            }
        }
        return lastLength;
    }
};

class Solution_1 {
  public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;
        }
        return len;
    }
};
//Runtime: 3 ms
class Solution_2 {
  public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ')
            tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};