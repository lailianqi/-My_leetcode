#include <algorithm>
#include <string>
using namespace std;
//自己写的
// Your runtime beats 34.76 % of cpp submissions.
class Solution {
  public:
    void reverseWords(string &s) {
        remove_surplus_spaces(s);
        if (s.size() == 0)
            return;
        reverse(s.begin(), s.end());
        int i = 0;
        int start = 0, end = 0;
        while (i < s.length() - 1) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
                start = i + 1;
            }
            if (s[i] != ' ' && s[i + 1] == ' ' || i == s.length() - 2) {
                if (i == s.length() - 2) {
                    end = i + 2;
                } else
                    end = i + 1;
                reverse(s.begin() + start, s.begin() + end);
            }
            i++;
        }
    }
    string &trim(string &s) {
        if (s.empty()) {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
    void remove_surplus_spaces(string &s) {
        string src = trim(s);
        string result = "";
        for (int i = 0; src[i] != '\0'; i++) {
            if (src[i] != ' ') {
                result.append(1, src[i]);
            } else {
                if (src[i + 1] != ' ')
                    result.append(1, src[i]);
            }
        }
        s = result;
    }
};
// https://discuss.leetcode.com/topic/3298/in-place-simple-solution
// LeetCode的答案
class Solution {
  public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0)
                    s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ')
                    s[storeIndex++] = s[j++];
                reverse(s.begin() + storeIndex - (j - i),
                        s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
};

void test() {
    Solution s;
    string str = "    ";
    s.reverseWords(str);
}