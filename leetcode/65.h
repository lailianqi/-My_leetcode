#include <string>
using namespace std;
/*
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true*/
//参照答案
class Solution {
  public:
    bool isNumber(string s) {
        while (s[0] == ' ')
            s.erase(0, 1); // delete the  prefix whitespace
        while (s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1); // delete the suffix whitespace
        bool pointSeen = false;
        bool eSeen = false;
        bool numberSeen = false;
        bool numberAfterE = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if (s[i] == '.') {
                if (eSeen || pointSeen) {
                    return false;
                }
                pointSeen = true;
            } else if (s[i] == 'e') {
                if (eSeen || !numberSeen) {
                    return false;
                }
                eSeen = true;
                numberAfterE = false;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return numberSeen && numberAfterE;
    }
};